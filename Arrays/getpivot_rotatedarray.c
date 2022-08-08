#include <stdio.h>

// https://www.techcrashcourse.com/2016/07/program-to-search-element-in-sorted-rotated-array.html

i#include <stdio.h>


int main()
{
   int array[] = {9,3,4,5};
   int start,end,middle,pivot;
   int size;
   
   start = 0;
   size = sizeof(array)/sizeof(array[0]);
   end = size - 1;
   
   if (size == 0)
        printf("Empty array\n");
    
    if (end == 0 )
        printf("Pivot: %d", array[start]);
   
   while(start <= end){
       
       middle = (start + end)/2;

       if (array[middle]>array[ middle+1]){
           pivot = middle + 1;
            break;
       }
       
       if (array[middle] >= array[start]){
           start = middle+1;
       }
      else
           end = middle-1;
       
   }

   printf("%d",array[pivot]);

  return 0;
}


