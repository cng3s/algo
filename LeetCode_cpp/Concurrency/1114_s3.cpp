// 执行用时：120 ms, 在所有 C++ 提交中击败了86.88% 的用户
// 内存消耗：7.1 MB, 在所有 C++ 提交中击败了85.31% 的用户

class Foo {
public:
    Foo() {
        pthread_mutex_init(&firstDone_, NULL);
        pthread_mutex_init(&secondDone_, NULL);
        pthread_mutex_lock(&firstDone_);
        pthread_mutex_lock(&secondDone_);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.

        printFirst();
        pthread_mutex_unlock(&firstDone_);
    }

    void second(function<void()> printSecond) {
        pthread_mutex_lock(&firstDone_);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        pthread_mutex_unlock(&secondDone_);
    }

    void third(function<void()> printThird) {
        pthread_mutex_lock(&secondDone_);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

protected:
    pthread_mutex_t firstDone_, secondDone_;

};