// 执行用时：236 ms, 在所有 C++ 提交中击败了23.21% 的用户
// 内存消耗：9.1 MB, 在所有 C++ 提交中击败了70.48% 的用户

#include <semaphore.h>

class H2O {
public:
    H2O() : H2{ 0 } {
        sem_init(&mutexH, 0, 2);
        sem_init(&mutexO, 0, 1);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&mutexH);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++H2;
        if (H2 == 2) {
            H2.store(0);
            sem_post(&mutexO);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&mutexO);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        sem_post(&mutexH);
        sem_post(&mutexH);
    }

private:
    sem_t mutexH, mutexO;
    std::atomic<int> H2;
};