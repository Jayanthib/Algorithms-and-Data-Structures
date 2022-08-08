#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// About : Implement selection sort algorithm 
// 1. Find the position of minimum elemnt by iterating through array 
// 2. Swap the element in 0th position with the element found in minimum index (step)1
// 3. Repeat Step 1 for size-1 iterations


void swapnumbers(int* a,int* b);
void selection_sort(int* int_array,int size);

int main()
{

int i;
int int_array[] = {10,5,6,2};
int size;

size = sizeof(int_array)/sizeof(int_array[0]);

selection_sort(int_array,size);


return 0;

}

void selection_sort(int* int_array,int size){
  
  int i,j;
  int min_index;

  for(i=0;i<size-1;i++){
  	// Initialize minimum index
  	min_index = i;
  	// Inner loop to iterate over elements starting from i+1 **
  	for(j=i+1;j<size;j++){
  		if (int_array[j] < int_array[min_index]){
  			min_index = j;
  		}
  	}
  	swapnumbers(&int_array[i],&int_array[min_index]);
  }

  //Sorted integer
for(i=0;i<4;i++)
    printf("%d\n",int_array[i]);


}

void swapnumbers(int* a,int* b){
	int temp = *a;  
    *a = *b;  
    *b = temp;  
}
