#include "ThreadPool.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THREADPOOL_INIT_COUNT       20
#define TASK_INIT_SIZE              1000

void task_entry(struct Task* task)
{
  int idx = *(int*) task->user_data;
  printf("idx: %d\n", idx);

  free(task->user_data);
  free(task);
}

int main( void )
{
  ThreadPool pool = {0};

  ThreadPool_Create(&pool, THREADPOOL_INIT_COUNT);

  int i = 0;
  for (i = 0; i < TASK_INIT_SIZE; ++i) {
    struct Task *task = (struct Task*) malloc(sizeof(struct Task));
    if (task == NULL) {
      perror("malloc error");
      exit(1);
    }
    memset(task, 0, sizeof(struct Task));

    task->task_func = task_entry;
    task->user_data = malloc(sizeof(int));
    *(int*) task->user_data = i;

    ThreadPool_PushTask(&pool, task);
  }

  getchar();
  return 0;
}
