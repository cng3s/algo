// 超时
class ZeroEvenOdd {
private:
    int n;
    std::mutex zeroPrint_, evenPrint_, oddPrint_;
    int num;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        num = 1;
        oddPrint_.lock();
        evenPrint_.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (auto i = 0; i < n; ++i) {
            zeroPrint_.lock();
            printNumber(0);
            if (num & 1) {
                oddPrint_.unlock();
            }
            else {
                evenPrint_.unlock();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (auto i = 2; i <= n; i += 2) {
            evenPrint_.lock();
            printNumber(i);
            zeroPrint_.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (auto i = 1; i <= n; i += 2) {
            oddPrint_.lock();
            printNumber(i);
            oddPrint_.unlock();
        }
    }
};