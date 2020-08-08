// 执行用时：132 ms, 在所有 C++ 提交中击败了73.34% 的用户
// 内存消耗：7.2 MB, 在所有 C++ 提交中击败了60.41% 的用户

#include <semaphore.h>

class Foo {
public:
    Foo() {
        sem_init(&firstDone_, 0, 0);
        sem_init(&secondDone_, 0, 0);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&firstDone_);
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstDone_);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&secondDone_);
    }

    void third(function<void()> printThird) {
        sem_wait(&secondDone_);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

protected:
    sem_t  firstDone_;
    sem_t  secondDone_;
};