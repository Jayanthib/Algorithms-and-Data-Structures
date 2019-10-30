#include<stdio.h>
#include<stdlib.h>

// About      : Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//              This is based on binary search algorithm. We search the first half of array to find the start index of the range and
//              second half of array to find the end index of range.
// Complexity : 0(logn)


int get_element_index(int* nums, int numsSize, int target,int searchFirsthalf);
int* searchRange(int* nums, int numsSize, int target, int* returnSize);

int main(){
  int nums[] = {5,7,7,8,8,10};
  int target = 8;
  int numsSize = 6;
  int* returnSize;
  int resultsize;

  returnSize = &resultsize;
  searchRange(nums,numsSize,target,returnSize);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){

    int low;
    int high;

    int* return_arr;

    return_arr = (int*) malloc(2 * sizeof(int));
    // We use flag to indicate if the search is in first half or second half
    low = get_element_index(nums,numsSize, target, 1);
    printf("Low - %d\n",low);
    high = get_element_index(nums, numsSize, target, 0);
    printf("High - %d\n",high);

    *return_arr = low;
    *(return_arr+1) = high;

    *returnSize = 2;

    return return_arr;

}

int get_element_index(int* nums, int numsSize, int target,int searchFirsthalf){

    int start = 0;
    int end = numsSize-1;
    int result = -1;
    int mid;

    while(start<=end){

        mid = (start+end)/2;

        if(nums[mid] == target){
            result = mid;
            if(searchFirsthalf)
                end = mid-1;
            else
                start = mid + 1;
        }

        else {
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid -1;
        }

    }

    return result;
}
