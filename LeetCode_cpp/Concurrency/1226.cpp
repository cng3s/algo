// 执行用时：188 ms, 在所有 C++ 提交中击败了42.25% 的用户
// 内存消耗：11.2 MB, 在所有 C++ 提交中击败了88.00% 的用户
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
        putRightFork();
        pthread_mutex_unlock(&forks[rightfork]);
        pthread_mutex_unlock(&forks[leftfork]);
    }

private:
    pthread_mutex_t forks[5];
};