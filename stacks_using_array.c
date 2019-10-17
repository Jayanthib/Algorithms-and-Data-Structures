#include<stdio.h>

#define MAX_SIZE 10

// Global structure variable describing stack
struct arraystack{
  int top = -1;
  int* item;
};

typedef struct arraystack arraystack;
arraystack* stack;

// Stack operations : Push/Pop/Top/Print

bool init(int size){

  stack = (arraystack*)malloc(sizeof(arraystack));

  if(stack == NULL)
    return 0;

  stack->item = (int*) malloc(sizeof(int)*size);

  if(stack->item == NULL)
    return 0;

  return 1;
}

// bool push(int val){
//   // Check if stack is full
//   if(stack->top == MAX_SIZE){
//     printf("Stack is full!");
//     return 0;
//   }
//   // Insert item
//   stack->top = stack->top + 1;
//   stack->item[stack->top]=val;
//   return 1;
// }
//
// int pop(void){
//   // Check if stack is empty
//   if(stack->top == -1){
//     printf("Stack is empty!");
//     return 0;
//   }
//   // Insert item
//   stack->top = stack->top + 1;
//   stack->item[stack->top]=val;
//   return 1;
// }


int main(){
  int size;

  //Provide size of Stack
  printf("Enter the max. size of stack\n);
  scanf("%d",&size);
  if(init(size))
    printf("Stack of size %d initialized!");
}
