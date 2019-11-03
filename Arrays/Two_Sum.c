#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// About     : Find two elements in a given array that adds up to a given sum.
// Algorithm : Sort the array and walk inwards using left and right pointers. Move them accordingly till you find the sum.

int cmpint (const void * a, const void * b);

int main()
{

int i;
int int_array[] = {10,5,6,2};
int* two_sum_array;

qsort(int_array,4,sizeof(int),cmpint);

two_sum_array = two_sum(int_array,4,7);

printf("Result : %d %d\n", *two_sum_array, *(two_sum_array+1));

return 0;

}

//Compare integer
int cmpint (const void * a, const void * b) {
   return (*(int*)a - *(int*)b);
}

int* two_sum(int* array, int array_size, int sum){

int* array_result;
int start = 0;
int end = array_size-1;

array_result = (int*)malloc(sizeof(int)*array_size);

  while(start < end){
    if (array[start]+array[end] == sum){
        found = 1;
        break;
    }
    if (array[start] + array[end] < sum)
          start++;
    else
          end--;
  }

  if (found == 1){
      *array_result = start;
      *(array_result+1) = end;
  }
  else{
      *array_result = -1;
      *(array_result+1) = -1;
  }

  return array_result;
}
