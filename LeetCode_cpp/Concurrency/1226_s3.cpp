// 执行用时：196 ms, 在所有 C++ 提交中击败了29.07% 的用户
// 内存消耗：11.4 MB, 在所有 C++ 提交中击败了46.67% 的用户
// 劣质优化：std::this_thread::yield();
// 其实这个优化在竞态过于激烈的场景下可能是好优化
// 而s2可能再在过于激烈的场景下是差优化
class DiningPhilosophers {
public:
    DiningPhilosophers() {
        for (auto i = 0; i < 5; ++i) {
            pthread_mutex_init(&forks[i], NULL);
            pthread_mutex_unlock(&forks[i]);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		int leftfork = philosopher, rightfork = (philosopher+1) % 5;
        int ret1 = 1, ret2 = 1;
        while (ret1 || ret2) {
            if (ret1 == 0)
                pthread_mutex_unlock(&forks[leftfork]);
            if (ret2 == 0)
                pthread_mutex_unlock(&forks[rightfork]);
            std::this_thread::yield();
            ret1 = pthread_mutex_trylock(&forks[leftfork]);
            ret2 = pthread_mutex_trylock(&forks[rightfork]);
        }

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        pthread_mutex_unlock(&forks[leftfork]);
        putRightFork();
        pthread_mutex_unlock(&forks[rightfork]);
    }

private:
    pthread_mutex_t forks[5];
};