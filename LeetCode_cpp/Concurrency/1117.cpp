// 执行用时：252 ms, 在所有 C++ 提交中击败了14.11% 的用户
// 内存消耗：9.1 MB, 在所有 C++ 提交中击败了57.14% 的用户

// std::this_thread::yield()是过一个yield时间片后再判断一次while条件
// 项目中用事件驱动方法比它好，当它比忙等好

class H2O {
public:
    H2O() : H2{ 0 } {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        while (H2.load() > 1)
            std::this_thread::yield();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++H2;
    }

    void oxygen(function<void()> releaseOxygen) {
        while (H2.load() != 2)
            std::this_thread::yield();

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        H2.store(0);
    }

private:
    std::atomic<int> H2;
};


/*
// 错误写法：
// 用if判断，则std::this_thread::yield()过一个yield时间片后直接执行后面的语句
//
class H2O {
public:
    H2O() : H2{ 0 } {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        if (H2.load() > 1)
            std::this_thread::yield();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++H2;
    }

    void oxygen(function<void()> releaseOxygen) {
        if (H2.load() != 2)
            std::this_thread::yield();

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        H2.store(0);
    }

private:
    std::atomic<int> H2;
};

*/