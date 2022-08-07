// 执行用时：128 ms, 在所有 C++ 提交中击败了78.47% 的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了19.59% 的用户


class Foo {
public:
    Foo() {
        firstDone_.lock();
        secondDone_.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstDone_.unlock();
    }

    void second(function<void()> printSecond) {
        firstDone_.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondDone_.unlock();
    }

    void third(function<void()> printThird) {
        secondDone_.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

protected:
    std::mutex firstDone_;
    std::mutex secondDone_;
};