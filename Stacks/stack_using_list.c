#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// About : Implement stack using array.
// API's : Push, Pop, Print stack

// Global structure variable describing stack
// Buffer is un-bounded since we use linked list.


struct stackll{
    int data;
    struct stackll* next;
};

struct stackll* top;

bool init( ){
 top = NULL;
return 1;
}

// Push

  bool push(int val){

    struct stackll* new_node;

    new_node = (struct stackll*)malloc(sizeof(struct stackll));
    if (new_node == NULL)
        return 0;
    new_node->data = val;

    if (top == NULL)
        new_node->next = NULL;
    else
        new_node->next = top;

    top = new_node;

    return 1;
  }


  int pop(void){

      int val;

      if(top == NULL){
        printf("Stack is empty");
        return -1;
      }
      val = top->data;
      free (top);
      top = top->next;

      return val;
  }

  void printStack(void){

      struct stackll* node;

      node = top;

      while(node!=NULL){
          printf("%d\t",node->data);
          node = node->next;
      }
      printf("\n");
  }


int main( ){
   init();
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
