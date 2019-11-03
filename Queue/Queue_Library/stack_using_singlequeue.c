#include "queue.h"

// Implementation:
// Stack is implemented using a single queue
// Push operation  : Every time element is pushed into simulated stack, we enqueue the data at the tail of the queue.
//                   All the existing queue elements are removed from head and inserted back into queue towards the tail till the new element becomes the head of the queue.
//                   Push operation takes O(n) time since we ensure LIFO order
// Pop operation   : Pop operation takes O(1) time. We dequeue the head.


// Simulated Stack using single queue
struct Stack{
  struct Queue* queue;
};

struct Stack* stack;

// Initialize stack
bool stack_init(int size){
  stack = (struct Stack*)malloc(sizeof(struct Stack));
  if (stack == NULL)
    return 0;
  stack->queue = queue_init(size);
  if (stack->queue == NULL)
      return 0;
  return 1;
}

// Push element into stack and re-arrange the original queue contents in LIFO order
bool push(int value){
  int curr_size,val,i;
  curr_size = getQueuesize(stack->queue);
  // Enqueue current element
  enqueue(stack->queue,value);

  // Re-arrange queue elements in LIFO order
  for(i=0;i<curr_size;i++){
    val = dequeue(stack->queue);
    enqueue(stack->queue,val);
  }
  return 1;
}

// POP is straight-forward and head of the queue is the latest inserted item
int pop(void){
  return (dequeue(stack->queue));
}

bool empty(void){
  queue_free(stack->queue);
  free(stack);
  return 1;
}

int main(){
  int size;

  //Provide size of Stack
  printf("Enter the max. size of stack\n");
  scanf("%d",&size);

  if(stack_init(size))
    printf("Stack of size %d initialized!",size);
  else{
    printf("Stack un-initialized\n");
    exit(0);
  }

// Test code
 push(33);
 push(55);
 push(77);
 push(17);
 print_queue(stack->queue);
 pop();
 pop();
 print_queue(stack->queue);

 return 1;
}
