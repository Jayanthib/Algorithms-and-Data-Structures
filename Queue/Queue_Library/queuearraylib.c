#include "queue.h"

// About : Implement Queue using array
//         Queue is FIFO data structure. Data is removed from head and inserted from tail of queue.
// Note  : API's here take struct Queue* Q has one of the inputs. This is keeping in mind that this could be expanded as library for any application that would pass a pointer to queue and use the libraray API's



struct Queue*  queue_init(int size){
  // Initialize queue
  struct Queue* queue;
  queue = (struct Queue*) malloc(sizeof(struct Queue));
  if (queue == NULL)
    return 0;
  queue->head = -1;
  queue->tail = -1;
  queue->max_size = size;
  queue->curr_size = 0;
  queue->buffer = (int*)malloc(sizeof(int)*size);
  if (queue->buffer == NULL)
    return NULL;

  return queue;
}

void queue_free(struct Queue* queue){
  free(queue->buffer);
  free(queue);
}

bool enqueue(struct Queue* queue,int data){

  if (isQueuefull(queue)){
    return 0;
  }

  if (queue->head == -1 && queue->tail == -1){
      queue->head = 0;
      queue->tail = 0;
    }
  else
    queue->tail = (queue->tail + 1)%(queue->max_size);

    queue->buffer[queue->tail] = data;
    queue->curr_size = (queue->curr_size + 1);

   return 1;
}

int dequeue(struct Queue* queue){
  int val;

  if (isQueueempty(queue)){
      return -1;
  }

  val = queue->buffer[queue->head];

  // If Dequeuing the last element in the Q
  if (queue->head == queue->tail){
      queue->head = -1;
      queue->tail = -1;
  }
  else
    queue->head = (queue->head + 1)%(queue->max_size);

    queue->curr_size = (queue->curr_size-1);
    // printf("de val = %d head -- %d\n",val,queue->buffer[queue->head]);

    return val;
}

bool isQueuefull(struct Queue* queue){
  if((queue->tail+1)%(queue->max_size) == (queue->head)){
      printf("\nQueue is full\n");
    return 1;
  }
  else
    return 0;
}

bool isQueueempty(struct Queue* queue){
  if(queue->head == -1 && queue->tail == -1){
      printf("Queue is empty\n");
    return 1;
  }
  else
    return 0;
}

int getQueuesize(struct Queue* queue){
  return queue->curr_size;
}

void print_queue(struct Queue* queue){
    int i,index;

    if (isQueueempty(queue)){
        return ;
    }
    index = queue->head;
    printf("\n");

    for(i=0;i<queue->curr_size;i++){
        printf("%d\t",queue->buffer[index]);
        index = (index+1)%queue->max_size;
      }

    printf("\n");
}
