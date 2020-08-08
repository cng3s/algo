// 执行用时：36 ms, 在所有 C++ 提交中击败了76.61% 的用户
// 内存消耗：7 MB, 在所有 C++ 提交中击败了53.33% 的用户

class FizzBuzz {
private:
    int n, i;

public:
    FizzBuzz(int n) : i { 1 } {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (1) {
            if (i == n + 1)
                break;
            if (i % 3 == 0 && i % 5 != 0) {
                printFizz();
                ++i;
            }
            else {
                std::this_thread::yield();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (1) {
            if (i == n + 1)
                break;
            if (i % 5 == 0 && i % 3 != 0) {
                printBuzz();
                ++i;
            }
            else {
                std::this_thread::yield();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (1) {
            if (i == n + 1)
                break;
            if (i % 15 == 0) {
                printFizzBuzz();
                ++i;
            }
            else {
                std::this_thread::yield();
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (1) {
            if (i == n + 1)
                break;
            if (i % 3 != 0 && i % 5 != 0) {
                printNumber(i);
                ++i;
            }
            else {
                std::this_thread::yield();
            }
        }
    }
};