#include "stack.h"

// About : Implement Queue using Stack
// Algorithm : Push operation in O(n) time and pop operation in O(1)
//             Enqueue : Use two stacks. Push element in first stack and pop them all in second stack.
//             Dequeue : Pop element of stack since the top points to first element inserted.

struct myqueue{
  Stack* main_stack;
  Stack* aux_stack;
};

struct myqueue* queue;

bool myqueue_init(int size){
   queue->main_stack = (Stack*)stack_init(size);
   if (queue->main_stack == NULL)
      return 0;
   queue->aux_stack = (Stack*)stack_init(size);
   if (queue->aux_stack == NULL)
      return 0;
   return 1;
}

// Emulate inserting into the tail of queue using stack
bool myqueue_enqueue(int data){
  int val;
  Stack* tmp;

  if (!push(queue->main_stack,data))
      return 0;

  while(!isStackfull(queue->main_stack)){
    val = pop(queue->main_stack);
    push(queue->aux_stack,val);
  }

  tmp = queue->main_stack;
  queue->main_stack = queue->aux_stack;
  queue->aux_stack = tmp;

  return 1;
}

// Emulate dequeuing of element from the head of the queue.
int myqueue_dequeue(void){
  return (pop(queue->main_stack));
}


bool myqueue_free(void){
  stack_free(queue->main_stack);
  stack_free(queue->aux_stack);
  return 1;
}

int main(){

  int q_size;

  printf("Enter the size of queue\n");
  scanf("%d",&q_size);

  queue = myqueue_init(q_size);
  // Initialize queue
  if (queue)
      printf("Queue of size %d inititalized!\n", q_size);
  else
    {
      printf("Unable to initialize queue\n");
      exit(1);
    }

  // Perform enquing
  myqueue_enqueue(queue,5);
  myqueue_enqueue(queue,7);
  myqueue_enqueue(queue,8);
  myqueue_enqueue(queue,9);
  printStack(queue);
  myqueue_dequeue(queue);
  printStack(queue);
  myqueue_dequeue(queue);
  // print_queue(queue);
  // dequeue(queue);
  // dequeue(queue);
  // printf("Current size : %d, Max size : %d\n",getQueuesize(queue),queue->max_size);
  queue_free(queue);

  // Call test suite
  //  queue_test_suite();

return 0;

}
