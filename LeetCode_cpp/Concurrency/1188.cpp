// 执行用时：136 ms, 在所有 C++ 提交中击败了8.33% 的用户
// 内存消耗：9.2 MB, 在所有 C++ 提交中击败了45.00% 的用户

#include <semaphore.h>

class BoundedBlockingQueue {
private:
    int capacity_, size_;
    sem_t sem_full_, sem_empty_;
    queue<int> q_;
    pthread_mutex_t mutex_;


public:
    BoundedBlockingQueue(int capacity) 
        : capacity_{capacity}, size_{0} {
        sem_init(&sem_full_, 0, 0);
        sem_init(&sem_empty_, 0, capacity_);
        pthread_mutex_init(&mutex_, NULL);
        pthread_mutex_unlock(&mutex_);
    }
    
    void enqueue(int element) {
        sem_wait(&sem_empty_);
        q_.emplace(element);
        pthread_mutex_lock(&mutex_);
        ++size_;
        pthread_mutex_unlock(&mutex_);
        sem_post(&sem_full_);
    }
    
    int dequeue() {
        sem_wait(&sem_full_);
        auto ret = q_.front();
        q_.pop();
        pthread_mutex_lock(&mutex_);
        --size_;
        pthread_mutex_unlock(&mutex_);
        sem_post(&sem_empty_);
        return ret;
    }
    
    int size() {
        return size_;
    }
};