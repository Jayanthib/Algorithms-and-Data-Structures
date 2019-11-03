#include "stack.h"

(Stack*) init(int size){

  stack = (Stack*) malloc(sizeof(Stack));
  if(stack == NULL)
    return NULL;

  stack->top = -1;
  stack->max_size = size;

  stack->item = (int*) malloc(sizeof(int)*size);
  if(stack->item == NULL)
    return NULL;

  return stack;
}

bool push(Stack* stack,int val){
  if(!isStackfull(stack))
    return 0;
  // Insert item
  stack->top = stack->top + 1;
  stack->item[stack->top]=val;
  return 1;
}

int pop(Stack* stack){
    int val;
    if(!isStackempty(stack))
       return -1;
  // remove item
  val = stack->item[stack->top];
  stack->top = stack->top - 1;

  return val;
}

void printStack(Stack* stack){
    int i;

    printf("\nStack : \t");

    if(stack->top == -1)
        printf("Empty\n");

    for(i=0;i<=stack->top;i++)
        printf("%d\t",stack->item[i]);

}

bool stack_free(Stack* stack){
  free(stack->item);
  free(stack);
  return 1;
}

bool isStackfull(Stack* stack){
  // Check if stack is full
  if(stack->top == stack->max_size){
    printf("\nStack is full!");
    return 1;
  }
  return 0;
}


bool isStackempty(Stack* stack){
  // Check if stack is empty
  if(stack->top == -1){
    printf("\nStack is empty!");
    return 1;
  }
  return 0;
}

void printStack(Stack* stack){
    int i;

    printf("\nStack : \t");

    if(stack->top == -1)
        printf("Empty\n");

    for(i=0;i<=stack->top;i++)
        printf("%d\t",stack->item[i]);

}
