// 执行用时：136 ms, 在所有 C++ 提交中击败了93.60% 的用户
// 内存消耗：11.3 MB, 在所有 C++ 提交中击败了62.67% 的用户
// 小优化：放下left fork以后马上释放left锁
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