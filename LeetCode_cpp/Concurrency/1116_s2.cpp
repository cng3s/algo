// 执行用时：64 ms, 在所有 C++ 提交中击败了23.97% 的用户
// 内存消耗：7.1 MB, 在所有 C++ 提交中击败了64.76% 的用户

#include <semaphore.h>

class ZeroEvenOdd {
private:
    int n;
    sem_t sem0, sem1, sem2;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&sem0, 0, 1);
        sem_init(&sem1, 0, 0);
        sem_init(&sem2, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (auto i = 1; i <= n; ++i) {
            sem_wait(&sem0);
            printNumber(0);
            if (i & 1)
                sem_post(&sem1);
            else
                sem_post(&sem2);
        }
    }

    void even(function<void(int)> printNumber) {
        for (auto i = 2; i <= n; i += 2) {
            sem_wait(&sem2);
            printNumber(i);
            sem_post(&sem0);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (auto i = 1; i <= n; i += 2) {
            sem_wait(&sem1);
            printNumber(i);
            sem_post(&sem0);
        }
    }
};