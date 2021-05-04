#include <thread>
#include <iostream>
#include <memory>
#include <vector>
#include <windows.h>

#include "ThreadPool.h"

using namespace std;

class TestThread {
public:
    void print(int i, int j, int k) {
        printf("\n%ld - %d - %d - %d\n", GetCurrentThreadId(), i, j, k);
    }
};

void TestThreadPool()
{
    ThreadPool pool;
    std::thread thread1([&pool] {
        for (int i = 0; i < 10; ++i) {
            auto thdId = this_thread::get_id();
            pool.AddTask([thdId]{ printf("sync thread1's threadID: %d\n", thdId); });
        }
    });

    std::thread thread2([&pool] {
        for (int i = 0; i < 10; ++i) {
            auto thdId = this_thread::get_id();
            pool.AddTask([thdId]{ printf("sync thread2's threadID: %d\n", thdId); });
        }
    });


    this_thread::sleep_for(std::chrono::seconds(2));
    getchar();
    pool.Stop();
    thread1.join();
    thread2.join();
}

int main() {
    /*vector<unique_ptr<thread>> threads;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                threads.emplace_back(make_unique<thread>(&TestThread::print, TestThread(), i, j, k));
                threads.back()->join();
            }
        }
    }*/

    TestThreadPool();
}