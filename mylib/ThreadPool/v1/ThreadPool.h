#pragma once

#include <list>
#include <thread>
#include <functional>
#include <memory>
#include <atomic>

#include "SyncQueue.h"

using namespace std;

const int kMaxTaskCount = 100;

class ThreadPool {
public:
    using Task = std::function<void()>;

    ThreadPool(int numThreads = std::thread::hardware_concurrency())
        : m_queue(kMaxTaskCount)
    {
        Start(numThreads);
    }

    ~ThreadPool()
    {
        Stop();
    }

    void Stop()
    {   // ��֤���ߴ������ֻ����һ��StopThreadGroup
        std::call_once(m_flag, [this]{ StopThreadGroup(); });
    }

    void AddTask(Task&& task)
    {
        m_queue.Put(std::forward<Task>(task));
    }

    void AddTask(const Task& task)
    {
        m_queue.Put(task);
    }

private:
    void StopThreadGroup()
    {
        m_queue.Stop();         // ��ͬ�������е��߳�ֹͣ
        m_running = false;      // ����Ϊfalse�����ڲ��߳�����ѭ�����˳�

        for (auto &thread : m_threadGroup) {
            if (thread)
                thread->join();
        }
        m_threadGroup.clear();
    }

    void RunInThread()
    {
        while (m_running)
        {
            std::list<Task> taskList;
            m_queue.Take(taskList);

            for (auto& task : taskList)
            {
                if (!m_running)
                    return;
                task();
            }
        }
    }

    void Start(int numThreads)
    {
        m_running = true;
        for (int i = 0; i < numThreads; ++i)
            m_threadGroup.emplace_back(
                std::make_shared<std::thread>(&ThreadPool::RunInThread, this));
    }

private:
    std::list<std::shared_ptr<std::thread>> m_threadGroup;
    SyncQueue<Task> m_queue;
    atomic_bool m_running;
    std::once_flag m_flag;
};
