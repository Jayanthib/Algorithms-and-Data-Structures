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
struct Queue_list{
  int data;
  struct Queue_list* next;
};

struct Queue_list* head;
struct Queue_list* tail;

bool queue_init(void){

  head = NULL;
  tail = NULL;
return 1;
}

void queue_free(void){

}

bool enqueue(int data){

  struct Queue_list* node;

  node = (struct Queue_list*) malloc(sizeof(struct Queue_list));
  if (node == NULL)
    return 0;
  node->next = NULL;
  node->data = data;

  if (isQueueempty()){
    head = node;
    tail = node;
  }
  else{
    tail->next = node;
    tail = node;
  }

return 1;

}

int dequeue(void){

  int value;
  struct Queue_list* tmp;

  if (isQueueempty()){
      printf("Queue is empty\n");
    return -1;
  }

   value = head->data;
   tmp = head;
   head = head->next;
   if(head == NULL)
    tail = NULL;
   free(tmp);
   return value;
  }



bool isQueueempty(void){
  if ((head == NULL) && (tail == NULL)){
    return 1;
  }
  return 0;
}

void print_queue(void){
  struct Queue_list* tmp;
  tmp = head;

  while(tmp!=NULL){
    printf("%d\t",tmp->data);
    tmp = tmp->next;
  }

  printf("\n");
}

int main(){

  // Initialize queue
  if (queue_init())
      printf("Queue inititalized!\n");
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
  dequeue();
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

    assert(queue_init() == 1);

    for(i=0;i<5;i++)
        assert(enqueue(test_array[i])==1);

    print_queue();

     for(i=0;i<5;i++)
        assert(dequeue()==test_array[i]);

    print_queue();


}
