// ִ����ʱ��324 ms, ������ C++ �ύ�л�����52.15% ���û�
// �ڴ����ģ�8.2 MB, ������ C++ �ύ�л�����74.17% ���û�
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