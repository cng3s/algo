// 执行用时：324 ms, 在所有 C++ 提交中击败了52.15% 的用户
// 内存消耗：8.2 MB, 在所有 C++ 提交中击败了74.17% 的用户
#include <semaphore.h>

class FooBar {
private:
    int n;
    sem_t fooPrint_, barPrint_;


public:
    FooBar(int n) {
        this->n = n;
        sem_init(&barPrint_, 0, 0);
        sem_init(&fooPrint_, 0, 1);
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            sem_wait(&fooPrint_);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem_post(&barPrint_);
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            sem_wait(&barPrint_);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem_post(&fooPrint_);
        }
    }
};