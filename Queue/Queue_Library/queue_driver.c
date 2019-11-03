#include "queue.h"

// bool queue_test_suite(void);

int main(){

  int q_size;
  struct Queue* queue;

  printf("Enter the size of queue\n");
  scanf("%d",&q_size);

  queue = queue_init(q_size);
  // Initialize queue
  if (queue)
      printf("Queue of size %d inititalized!\n", q_size);
  else
    {
      printf("Unable to initialize queue\n");
      exit(1);
    }

  // Perform enquing
  enqueue(queue,5);
  enqueue(queue,7);
  enqueue(queue,8);
  enqueue(queue,9);
  printf("Current size : %d, Max size : %d\n",getQueuesize(queue),queue->max_size);
  print_queue(queue);
  dequeue(queue);
  print_queue(queue);
  dequeue(queue);
  print_queue(queue);
  dequeue(queue);
  dequeue(queue);
  printf("Current size : %d, Max size : %d\n",getQueuesize(queue),queue->max_size);
  queue_free(queue);

  // Call test suite
  //  queue_test_suite();

return 0;

}


// bool queue_test_suite(void){
//
//
//     int i;
//
//     int test_array[6] = {10,20,30,40,50,60};
//
//     printf("Test suite begins\n");
//
//     assert(queue_init(5) == 1);
//
//     for(i=0;i<5;i++)
//         assert(enqueue(test_array[i])==1);
//
//     print_queue();
//
//      for(i=0;i<5;i++)
//         assert(dequeue()==test_array[i]);
//
//     print_queue();
//
//     return 1;
//
// }
