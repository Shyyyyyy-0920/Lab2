#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue *queue_create(void)
{
  //这里如果分配失败下面的size赋值会导致空指针解引用，所以要先判断分配是否成功
  Queue *queue = malloc(sizeof(Queue));
  if (!queue) {
    return NULL;
  }
  queue->size = 0;
  queue->capacity = QUEUE_INITIAL_CAPACITY;
  queue->data = malloc(sizeof(double) * queue->capacity);
  if (!queue->data) {
    free(queue);
    return NULL;
  }
  return queue;
}

void push(Queue *queue, double element)
{
  if(queue==NULL) {
    return;
  }
  if (queue->size == queue->capacity)
  {
    int capacity = queue->capacity * 2;//扩容
    //一旦失败，原来的地址会被覆盖掉，从而产生内存泄漏
    double *temp_data = realloc(queue->data, sizeof(double) * capacity);
    if (!temp_data) {
      return;
    }
    queue->data = temp_data;
    queue->capacity = capacity;
  }

  int insert_index = queue->size % queue->capacity;
  queue->data[insert_index] = element;
  queue->size++;
}

double back(Queue *queue)
{
  if(queue==NULL||queue->size==0) {
    return 0.0;
  }
  return queue->data[queue->size - 1];
}

void queue_free(Queue *queue)
{
  if(queue==NULL) {
    return;
  }
  free(queue->data);
  free(queue);
}

