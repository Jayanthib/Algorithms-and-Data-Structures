#ifndef STACK_H      // Inclusion guard.
#define STACK_H      // Inclusion guard.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

// Global data structure for queue.
struct Stack{
  int top;
  int max_size;
  int *item;
};

typedef struct Stack Stack;

Stack* stack_init(int size);
void stack_free(Stack* stack);
bool push(Stack* stack,int data);
int pop(Stack* stack);
bool isStackfull(Stack* stack);
bool isStackempty(Stack* stack);
void print_stack(Stack* stack);

#endif
