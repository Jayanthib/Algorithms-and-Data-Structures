#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX_SIZE 10

// About : Implement stack using array.
// API's : Push, Pop, Print stack

// Global structure variable describing stack
// Members : Top of the stack
//           Maximum size of the stack
//           Buffer pointing to stack items
struct arraystack{
  int top ;
  int max_size;
  int* item;
};

typedef struct arraystack arraystack;

arraystack* stack;

// Stack operations : Push/Pop/Top/Print

bool init(int size){

  stack = (arraystack*) malloc(sizeof(arraystack));
  if(stack == NULL)
    return 0;

  stack->top = -1;
  stack->max_size = size;

  stack->item = (int*) malloc(sizeof(int)*size);
  if(stack->item == NULL)
    return 0;

  return 1;
}

bool push(int val){
  // Check if stack is full
  if(stack->top == stack->max_size){
    printf("\nStack is full!");
    return 0;
  }
  // Insert item
  stack->top = stack->top + 1;
  stack->item[stack->top]=val;
  return 1;
}

int pop(void){
    int val;
  // Check if stack is empty
  if(stack->top == -1){
    printf("\nStack is empty!");
    return -1;
  }
  // remove item
  val = stack->item[stack->top];
  stack->top = stack->top - 1;

  return val;
}

void printStack(){
    int i;

    printf("\nStack : \t");

    if(stack->top == -1)
        printf("Empty\n");

    for(i=0;i<=stack->top;i++)
        printf("%d\t",stack->item[i]);

}

int main(){
  int size;
  int val;

  //Provide size of Stack
  printf("Enter the max. size of stack\n");
  scanf("%d",&size);

  if(init(size))
    printf("Stack of size %d initialized!",size);
  else{
    printf("Stack un-initialized\n");
    exit(0);
  }

 push(3);
 push(5);
 push(7);
 push(17);
 printStack();
 pop();
 printStack();
 pop();
 pop();
 pop();
 pop();
 printStack();

  return 0;
}
