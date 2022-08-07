// 执行用时：76 ms, 在所有 C++ 提交中击败了88.89% 的用户
// 内存消耗：9.1 MB, 在所有 C++ 提交中击败了55.00% 的用户

#include <semaphore.h>

class BoundedBlockingQueue {
private:
    int capacity_;
    sem_t sem_full_, sem_empty_;
    queue<int> q_;


public:
    BoundedBlockingQueue(int capacity) 
        : capacity_{capacity} {
        sem_init(&sem_full_, 0, 0);
        sem_init(&sem_empty_, 0, capacity_);
    }
    
    void enqueue(int element) {
        sem_wait(&sem_empty_);
        q_.emplace(element);
        sem_post(&sem_full_);
    }
    
    int dequeue() {
        sem_wait(&sem_full_);
        auto ret = q_.front();
        q_.pop();
        sem_post(&sem_empty_);
        return ret;
    }
    
    int size() {
        return q_.size();
    }
};