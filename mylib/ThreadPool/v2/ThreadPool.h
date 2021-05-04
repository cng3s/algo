#include <pthread.h>

// 头插法链表插入结点
#define LIST_INSERT(item, list) do {         \
  item->prev = NULL;                         \
  item->next = list;                         \
  if ((list) != NULL) (list)->prev = item;   \
  (list) = item;                             \
} while( 0 )

// 链表结点移除
#define LIST_REMOVE(item, list) do {                        \
  if (item->prev != NULL) item->prev->next = item->next;    \
  if (item->next != NULL) item->next->prev = item->prev;    \
  if (list == item) list = item->next;                      \
  item->prev = item->next = NULL;                           \
} while( 0 )



// 任务队列结点
// task_func: 处理任务的函数
// user_data: 待处理的数据
// prev/next: 链表前后结点
struct Task {
  void (*task_func)(struct Task *arg);
  void *user_data; // 用来执行task_func的参数，即task_func(user_data)

  struct Task *prev;
  struct Task *next;
};

// 执行任务的结点
struct Worker {
  pthread_t threadid; // 线程id
  struct Manager *manager; // 执行任务的父调度器，方便操作

  int terminate; // 是否终止该执行任务结点
  
  struct Worker *prev;
  struct Worker *next;
};


// 调度器
typedef struct Manager {
  struct Task   *tasks;   // 任务队列
  struct Worker *workers; // 执行队列

  pthread_mutex_t mutex; // 互斥量，保证任务调度有序执行
  pthread_cond_t  cond;  // 唤起执行任务结点的条件
} ThreadPool;

int ThreadPool_Create(ThreadPool *pool, int workerNum);

int ThreadPool_PushTask(ThreadPool *pool, struct Task *task);

int ThreadPool_Destory(ThreadPool *pool);
