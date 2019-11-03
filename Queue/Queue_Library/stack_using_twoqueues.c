#include "queue.h"

// Implementation:
// Stack is implemented using a single queue
// Push operation  : Every time element is pushed into simulated stack, we enqueue the data at the tail of the queue.
//                   All the existing queue elements are removed from head and inserted back into queue towards the tail till the new element becomes the head of the queue.
//                   Push operation takes O(n) time since we ensure LIFO order
// Pop operation   : Pop operation takes O(1) time. We dequeue the head.


// Simulated Stack using single queue
struct Stack{
  struct Queue* main_queue;
  struct Queue* aux_queue;
};

struct Stack* stack;

// Initialize stack
bool stack_init(int size){
  stack = (struct Stack*)malloc(sizeof(struct Stack));
  if (stack == NULL)
    return 0;
  stack->main_queue = queue_init(size);
  if (stack->main_queue == NULL)
      return 0;
  stack->aux_queue = queue_init(size);
  if (stack->aux_queue == NULL)
      return 0;
  return 1;
}

// Push element into stack and re-arrange the original queue contents in LIFO order
bool push(int value){
  struct Queue* tmp;
  int val;

  // Check if Main queue is Full
    if(isQueuefull(stack->main_queue)){
      printf("Stack is full\n");
      return 0;
    }

  // Enqueue current element
  if(!enqueue(stack->aux_queue,value))
    return 0;

  while(!isQueueempty(stack->main_queue)){
    val = dequeue(stack->main_queue);
    enqueue(stack->aux_queue,val);
  }

  // Swap queues to ensure main queue is the one always with queue elements
  tmp = stack->main_queue;
  stack->main_queue = stack->aux_queue;
  stack->aux_queue = tmp;

  return 1;
}

// POP is straight-forward and head of the queue is the latest inserted item
int pop(void){
    if (!dequeue(stack->main_queue)){
      printf("Stack is empty\n");
      return 0;
    }
    return 1;
}

bool empty(void){
  queue_free(stack->main_queue);
  queue_free(stack->aux_queue);
  free(stack);
  return 1;
}

int main(){
  int size;

  //Provide size of Stack
  printf("Enter the max. size of stack\n");
  scanf("%d",&size);

  if(stack_init(size))
    printf("Stack of size %d initialized!\n",size);
  else{
    printf("Stack un-initialized\n");
    exit(0);
  }

// Test code
 push(33);
 push(55);
 push(77);
 push(17);
 print_queue(stack->main_queue);
 pop();
 pop();
 print_queue(stack->main_queue);

 return 1;
}
