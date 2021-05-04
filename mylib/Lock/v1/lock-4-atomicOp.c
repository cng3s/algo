// lock-1.c 问题程序：
// 创建10个线程，每个线程对同一个初始值为0的变量+10w，最后期望结果应该是100w
// 但是最后没有加到100w ，原因分析:
// (*pcount)++; --> 汇编指令：
// mov[count], eax;
// inc eax;
// mov eax, [count];
// 写速度比读速度慢得多，在写的过程中，有其他线程也读了数值，但读得数值是没有更新的
// 然后又重复写入，就导致了最后期望结果不是100w
//
// lock-2.c 修复问题：
// 通过互斥量加锁的方式，发现线程越多，程序执行速度越快，而且快非常多
//
// lock-3.c 使用自旋锁来加锁
// 因为该程序临界区操作极少，所以非常适合用自旋锁操作，性能更好
//
// lock-4.c 使用原子操作
// 原子操作把多个操作做成单条指令，在临界区操作极小的情况下性能极好，所以该程序非常适合

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


#define THREAD_COUNT      1000
#define ADD_TIMES         1000

//pthread_mutex_t mutex;
//pthread_spinlock_t spinlock;


// 原子操作包装函数，实现value += add
int inc(int *value, int add)
{
  int old;

  __asm__ volatile(
    "lock; xaddl %2, %1;" // %1 = %2 + %1
    : "=a" (old)
    : "m" (*value), "a"(add) // 解释%2,%1对应的值，%1 = value, %2 = add
    : "cc", "memory"
  );

  return old;
}

void* Thread_Callback(void *arg)
{
  int *pcount = (int*) arg;
  int i = 0;

  while (i++ < ADD_TIMES) { // 每个线程给pcount加10w
#if 0
    (*pcount)++;
#elif 0 // 互斥锁实现
    pthread_mutex_lock(&mutex);
    (*pcount)++;
    pthread_mutex_unlock(&mutex);
#elif 0 // 自旋锁实现
    pthread_spin_lock(&spinlock);
    (*pcount)++; // 因为这段代码消耗时间极少，所以用自旋锁性能更好
    pthread_spin_unlock(&spinlock);
#elif 1 // 原子操作实现
    inc(pcount, 1);
#endif
    usleep(1); // 每加一次休眠1us，使得现象更加明显
  }

  return NULL;
}

int main()
{
  pthread_t threadids[THREAD_COUNT] = {0};

  //pthread_mutex_init(&mutex, NULL);
  //pthread_spin_init(&spinlock, PTHREAD_PROCESS_SHARED);

  int i = 0, count = 0;
  for (i = 0; i < THREAD_COUNT; ++i) {
    pthread_create(&threadids[i], NULL, Thread_Callback, &count);   
  }

  for (i = 0; i < 100; ++i) {
    printf("count: %d\n", count);
    sleep(1);
  }

  return 0;
}
