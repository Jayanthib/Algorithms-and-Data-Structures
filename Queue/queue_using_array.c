#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

bool isQueuefull(void);
bool isQueueempty(void);
bool queue_test_suite(void);


// About : Implement Queue using array
//         Queue is FIFO data structure. Data is removed from head and inserted from tail of queue.

// Global data structure for queue.
struct Queue{
  int head;
  int tail;
  int q_size;
  int *buffer;
};

struct Queue* queue;


bool queue_init(int size){
  // Initialize queue
  queue = (struct Queue*) malloc(sizeof(struct Queue));
  if (queue == NULL)
    return 0;
  queue->head = -1;
  queue->tail = -1;
  queue->q_size = size;
  queue->buffer = (int*)malloc(sizeof(int)*size);
  if (queue->buffer == NULL)
    return 0;

  return 1;
}

void queue_free(void){
  free(queue->buffer);
  free(queue);
}

bool enqueue(int data){

  if (isQueuefull()){
    printf("Queue is full!\n");
    return 0;
  }

  if (queue->head == -1 && queue->tail == -1){
      queue->head = 0;
      queue->tail = 0;
    }
  else
    queue->tail = queue->tail + 1;

    queue->buffer[queue->tail] = data;

   return 1;
}

int dequeue(void){
  int val;

  if (isQueueempty()){
      printf("Queue is empty\n");
      return -1;
  }

  val = queue->buffer[queue->head];

  // If Dequeuing the last element in the Q
  if (queue->head == queue->tail){
      queue->head = -1;
      queue->tail = -1;
  }
  else
    queue->head = (queue->head + 1)%(queue->q_size);

    return val;
}

bool isQueuefull(void){
  if((queue->tail+1)%(queue->q_size) == (queue->head))
    return 1;
  else
    return 0;
}

bool isQueueempty(void){
  if(queue->head == -1 && queue->tail == -1)
    return 1;
  else
    return 0;
}

void print_queue(void){

    int i;

    if (isQueueempty()){
        printf("Queue is empty\n");
        return ;
    }

    for(i=queue->head;i<=queue->tail;i++)
        printf("%d\t",queue->buffer[i]);

    printf("\n");
}

int main(){

  int q_size;

  printf("Enter the size of queue\n");
  scanf("%d",&q_size);

  // Initialize queue
  if (queue_init(q_size))
      printf("Queue of size %d inititalized!\n", q_size);
  else
    {
      printf("Unable to initialize queue\n");
      exit(1);
    }

  // Perform enquing
  enqueue(5);
  enqueue(7);
  enqueue(8);
  enqueue(9);
  print_queue();
  dequeue();
  print_queue();
  dequeue();
  print_queue();
  dequeue();
  queue_free();

  // Call test suite
    queue_test_suite();

return 0;

}


bool queue_test_suite(void){


    int i;

    int test_array[6] = {10,20,30,40,50,60};

    printf("Test suite begins\n");

    assert(queue_init(5) == 1);

    for(i=0;i<5;i++)
        assert(enqueue(test_array[i])==1);

    print_queue();

     for(i=0;i<5;i++)
        assert(dequeue()==test_array[i]);

    print_queue();


}
