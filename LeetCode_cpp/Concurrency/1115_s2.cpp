// 执行用时：412 ms, 在所有 C++ 提交中击败了5.94% 的用户
// 内存消耗：8.2 MB, 在所有 C++ 提交中击败了89.40% 的用户

class FooBar {
private:
    int n;
    std::mutex fooPrint_, barPrint_;

public:
    FooBar(int n) {
        this->n = n;
        barPrint_.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            fooPrint_.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            barPrint_.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            barPrint_.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            fooPrint_.unlock();
        }
    }
};