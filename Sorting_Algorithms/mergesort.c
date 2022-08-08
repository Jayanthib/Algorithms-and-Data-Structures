#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_sort(int array[],int size);
void merge_divide(int array[],int left,int right);
void merge_conquer(int arr[],int left, int mid, int right);

int main()
{

int i;
int int_array[] = {10,5,6,2};
int size;

size = sizeof(int_array)/sizeof(int_array[0]);

merge_sort(int_array,size);

return 0;

}


void merge_sort(int array[],int size){

   int right;
   int left;
   
   left = 0;
   right = size-1;
   printf("s");
   // merge_divide(array,left,right);

}

void  merge_divide(int array[],int left,int right){


   int mid;



   while(left<right){
   	    mid = (left+right)/2;
	   	merge_divide(array,left,mid);
	   	merge_divide(array,mid+1,right);
        merge_conquer(array,left,mid,right);
   }

} 


void merge_conquer(int arr[],int left, int mid, int right){

     int left_size = mid - left + 1 ;
     int right_size = right - mid ;

     int left_arr[left_size];
     int right_arr[right_size];

     int i,j,k;
     
     j = left;
     for(i=0;i<left_size;i++)
     	left_arr[i] = arr[j++];

     j = mid+1;
     for(i=0;i<right_size;i++)
     	right_arr[i] = arr[j++];

     k = left;
     i = 0;
     j = 0;

     while ((i<left_size) || (j<right_size)){
     	if(left_arr[i] < right_arr[j]){
             arr[k++] = left_arr[i++]; 
     	  }
     	else
     		arr[k++] = right_arr[j++]; 
     	}

      while (i<left_size)
     	 arr[k++] = left_arr[i++];

      while (j<left_size)
     	arr[k++] = right_arr[j++];

}
