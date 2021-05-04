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
// 通过加锁的方式，发现线程越多，程序执行速度越快，而且快非常多
//


#include <stdio.h>
#include <pthread.h>


#define THREAD_COUNT      1000
#define ADD_TIMES         1000

pthread_mutex_t mutex;


void* Thread_Callback(void *arg)
{
  int *pcount = (int*) arg;
  int i = 0;

  while (i++ < ADD_TIMES) { // 每个线程给pcount加10w
#if 0
    (*pcount)++;
#else
    pthread_mutex_lock(&mutex);
    (*pcount)++;
    pthread_mutex_unlock(&mutex);
#endif
    usleep(1); // 每加一次休眠1us，使得现象更加明显
  }
}

int main()
{
  pthread_t threadids[THREAD_COUNT] = {0};

  pthread_mutex_init(&mutex, NULL);

  int i = 0, count = 0;
  for (i = 0; i < THREAD_COUNT; ++i) {
    pthread_create(&threadids[i], NULL, Thread_Callback, &count);   
  }

  for (i = 0; i < 100; ++i) {
    printf("count: %d\n", count);
    sleep(1);
  }
}
