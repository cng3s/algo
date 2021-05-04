#pragma once

#include <list>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;

template <typename T>
class SyncQueue {
public:
    SyncQueue(int maxSize)
        : m_maxSize(maxSize)
        , m_needStop(false)
    {}

    void Put(const T& x)
    {
        Add(x);
    }

    void Put(T&& x)
    {
        Add(std::forward<T>(x));
    }

    // 批量的Take缓冲区内容操作
    void Take(list<T>& l)
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        m_notEmpty.wait(locker, [this] { return m_needStop || NotEmpty(); });

        if (m_needStop) { return; }
        l = std::move(m_queue);
        m_notFull.notify_one();
    }

    void Take(T& t)
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        m_notEmpty.wait(locker, [this] { return m_needStop || NotEmpty(); });

        if (m_needStop) { return; }
        t = m_queue.front();
        m_queue.pop_front();
        m_notFull.notify_one();
    }

    void Stop()
    {
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            m_needStop = true;
        }
        m_notFull.notify_all();
        m_notEmpty.notify_all();
    }

    bool Empty()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.empty();
    }

    bool Full()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.size() == m_maxSize;
    }

    size_t Size()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.size();
    }

    int Count()
    {
        return m_queue.size();
    }

private:
    bool NotEmpty() const
    {
        bool empty = m_queue.empty();
        if (empty) {
            printf("m_queue is empty, need to wait..., async layer pthread ID: %p\n",
                   this_thread::get_id());
        }
        return !empty;
    }

    bool NotFull() const
    {
        bool full = m_queue.size() >= m_maxSize;
        if (full) {
            printf("m_queue is full, need to wait..., async layer pthread ID: %p\n",
                   this_thread::get_id());
        }
        return !full;
    }

    template <typename F>
    void Add(F&& x)
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        m_notFull.wait(locker, [this]{ return m_needStop || NotFull(); });
        if (m_needStop) { return; }

        m_queue.emplace_back(std::forward<F>(x));
        m_notEmpty.notify_one();
    }


private:
    std::list<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_notEmpty;
    std::condition_variable m_notFull;
    int m_maxSize;
    bool m_needStop;
};
