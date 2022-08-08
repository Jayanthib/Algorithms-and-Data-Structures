#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// About : Implement selection sort algorithm 
// 1. Compare first two elemenst in array
// 2. Swap the elements if first element is less than second
// 3. Repeat Step 1 for size-1 iterations


void swapnumbers(int* a,int* b);
void bubble_sort(int* int_array,int size);

int main()
{

int i;
int int_array[] = {10,5,6,2};
int size;

size = sizeof(int_array)/sizeof(int_array[0]);

bubble_sort(int_array,size);

return 0;

}

void bubble_sort(int* int_array,int size){
  
  int i,j;
  int min_index;

  for(i=0;i<size-1;i++){	
  	// Inner loop to iterate over elements starting from i+1 **
  	for(j=0;j<size-i-1;j++){
  		if (int_array[j+1] < int_array[j]){
  			swapnumbers(&int_array[j],&int_array[j+1]);
  		}
  	}
  	
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