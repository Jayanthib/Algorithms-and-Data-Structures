#include <stdio.h>
#include <stdlib.h>

//About : Check if the array is monotonically increasing or decreasing
// Algorithm : Use two flags isIncreasing & isDecreasing to track the status of element comparison.
//             If the status of either of the flags change, array is not monotonic.

int main()
{
int i;
int int_array[] = {10,5,6,2};
int size = sizeof(int_array)/sizeof(int_array[0]);

printf("%d\n",isMonotonic(int_array,size));
return 0;
}

bool isMonotonic(int* A, int ASize){

    int isIncreasing = 1;
    int isDecreasing = 1;
    int i;

    // For 'n' elements you make n-1 comparisons
    for(i=0;i<ASize-1;i++){
        if (A[i] > A[i+1])
            isIncreasing = 0;
        if (A[i] < A[i+1])
            isDecreasing = 0;
    }

    return (isIncreasing | isDecreasing);

}
