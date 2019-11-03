#ifndef QUEUE_H      // Inclusion guard.
#define QUEUE_H      // Inclusion guard.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

// Global data structure for queue.
struct Queue{
  int head;
  int tail;
  int max_size;
  int curr_size;
  int *buffer;
};


struct Queue* queue_init(int size);
void queue_free(struct Queue* queue);
bool enqueue(struct Queue* queue,int data);
int dequeue(struct Queue* queue);
bool isQueuefull(struct Queue* queue);
bool isQueueempty(struct Queue* queue);
int getQueuesize(struct Queue* queue);
void print_queue(struct Queue* queue);

#endif
