#include "ThreadPool.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


// 线程回调函数
static void* ThreadPool_Callback(void *arg)
{
  if (arg == NULL) {
    return NULL;
  }

  struct Worker *worker = (struct Worker*) arg;
  while (1) {
    pthread_mutex_lock(&worker->manager->mutex);

    while (worker->manager->tasks == NULL) { // 如果调度器中没有未处理的任务了，等待
      if (worker->terminate) {
        pthread_mutex_unlock(&worker->manager->mutex);
        goto EndHandler;
      }
      pthread_cond_wait(&worker->manager->cond, &worker->manager->mutex);
    }

    struct Task *task = worker->manager->tasks;
    LIST_REMOVE(task, worker->manager->tasks);

    pthread_mutex_unlock(&worker->manager->mutex); // 这么迟才解锁，其他的线程也阻塞了？

    task->task_func(task);
  }

EndHandler:

  free(worker);
  return arg;
}

// 创建一个新的线程池
// pool: 要创建的线程池指针
// workerNum: 执行者的数量
int ThreadPool_Create(ThreadPool *pool, int workerNum)
{
  // 校验参数，初始化
  if (pool == NULL)
    return -1;
  if (workerNum < 1)
    workerNum = 1;

  memset(pool, 0, sizeof(ThreadPool));

  pthread_cond_t blank_cond = PTHREAD_COND_INITIALIZER;
  memcpy(&pool->cond, &blank_cond, sizeof(pthread_cond_t));
  pthread_mutex_init(&pool->mutex, NULL);

  // 实现功能
  int i = 0;
  for (i = 0; i < workerNum; ++i) {
    struct Worker *worker = (struct Worker*)malloc(sizeof(struct Worker));
    if (worker == NULL) {
      perror("malloc error");
      return -2;
    }
    memset(worker, 0, sizeof(struct Worker)); // 刚创建好的数据，为了安全，一定要memset一下
    worker->manager = pool;
    int ret = pthread_create(&worker->threadid, NULL, ThreadPool_Callback, worker);
    if (ret) {
      perror("pthread_create error");
      free(worker);
      return -3;
    }

    pthread_mutex_lock(&pool->mutex);
    LIST_INSERT(worker, pool->workers);
    pthread_mutex_unlock(&pool->mutex);
  }

  return 0; // success
}


// 销毁一个线程池
int ThreadPool_Destory(ThreadPool *pool)
{
  if (pool == NULL)
    return -1;

  struct Worker *worker = NULL;
  for (worker = pool->workers; worker != NULL; worker = worker->next) {
    worker->terminate = 1;
  }

  // 广播，唤醒所有未满足条件沉睡的线程
  pthread_mutex_lock(&pool->mutex);
  pthread_cond_broadcast(&pool->cond);
  pthread_mutex_unlock(&pool->mutex);

  pool->workers = NULL;
  pool->tasks = NULL;

  return 0;
}


// 将任务放入线程池
// 丢入一个任务，通知一个沉睡的线程起床执行任务
int ThreadPool_PushTask(ThreadPool *pool, struct Task *task)
{
  if (pool == NULL || task == NULL)
    return -1;

  pthread_mutex_lock(&pool->mutex);
  LIST_INSERT(task, pool->tasks);
  pthread_cond_signal(&pool->cond); // 唤醒一个线程
  pthread_mutex_unlock(&pool->mutex);
  return 0;
}


