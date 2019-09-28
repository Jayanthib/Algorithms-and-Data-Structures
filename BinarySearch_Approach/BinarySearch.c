#include <stdio.h>

// Goal      : Implement binary search algorithm
// Note      : Input array is assumed to be sorted in ascending or descending order
// Tips      : Time complexity is O(logn) and space complexity is O(n)
// Approach  : Find the middle index of array.
//             If greater, decrement the end pointer to mid - 1
//             If lesser, increment the start pointer to mid + 1
//             If equal, return result

int binary_search(int* input_array,int array_size, int ele);

int main()
{
    int found;
    int input_array[ ] = {3,5,7,9,11,13,16};
    int array_size = sizeof(input_array)/input_array[0];
    int ele = 2;
    found = binary_search(input_array,array_size,ele);
    if (found)
        printf("Element %d found in array",ele);
    else
        printf("Element %d not found in array",ele);
    return 0;
}

int binary_search(int* input_array,int array_size, int ele){
    int start = 0;
    int end;
    int mid;

    if (array_size <=0)
        return 0;

    end = array_size-1;

    while(start<=end){

        mid = (start + end)/2;

        if(input_array[mid]==ele)
            return 1;
        if(ele < input_array[mid])
            end = end - 1;
        if (ele > input_array[mid])
            start = start + 1;
    }

     return 0;
}
