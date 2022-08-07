// 执行用时：40 ms, 在所有 C++ 提交中击败了84.64% 的用户
// 内存消耗：7 MB, 在所有 C++ 提交中击败了81.90% 的用户
class ZeroEvenOdd {
private:
    int n;
    pthread_mutex_t zeroPrint_, evenPrint_, oddPrint_;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        pthread_mutex_init(&zeroPrint_, NULL);
        pthread_mutex_init(&evenPrint_, NULL);
        pthread_mutex_init(&oddPrint_, NULL);

        pthread_mutex_lock(&oddPrint_);
        pthread_mutex_lock(&evenPrint_);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (auto i = 1; i <= n; ++i) {
            pthread_mutex_lock(&zeroPrint_);
            printNumber(0);
            if (i & 1) {
                pthread_mutex_unlock(&oddPrint_);
            }
            else {
                pthread_mutex_unlock(&evenPrint_);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (auto i = 2; i <= n; i += 2) {
            pthread_mutex_lock(&evenPrint_);
            printNumber(i);
            pthread_mutex_unlock(&zeroPrint_);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (auto i = 1; i <= n; i += 2) {
            pthread_mutex_lock(&oddPrint_);
            printNumber(i);
            pthread_mutex_unlock(&zeroPrint_);
        }
    }
};