#include <stdio.h>
#include <stdlib.h>

//About : Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
//        We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
//Algorithm : Have a counter to keep tab of comparisons that failed
//            counter == 0 --> Array is non-decreasing order
//            counter > 1  --> Array cannot be modified using just one element change
//            counter == 1 --> Consider corner cases. Ensure element before and after the index are non-decreasing.


int main()
{
int i;
int int_array[] = {10,5,6,2};
int size = sizeof(int_array)/sizeof(int_array[0]);

printf("%d\n",checkPossibility(int_array,size));
return 0;
}

bool checkPossibility(int* nums, int numsSize) {

    int count=0;
    int i;
    int index = -1;

    for(i=0;i<numsSize-1;i++){
        if (nums[i] > nums[i+1])
        {
            count++;
            index = i;
        }
    }

    if (count > 1)
        return 0;
    else
    {
        if (count == 0)
            return 1;
        // Corner Cases : False Positives
        if (count == 1)
        {
            // Case a: If index element is 0th or n-1th element
            if ((index == 0) |(index == numsSize-2 ))
                return 1;
            // Case B : Ensure elements around index element follow non-decreasing pattern ex: [3,4,2,3]
            if ( ( nums[index-1] < nums[index+1]))             {
                 return 1;
            }
            if  (( nums[index] < nums[index+2]))
                return 1;
        }

        return 0;
    }


}
