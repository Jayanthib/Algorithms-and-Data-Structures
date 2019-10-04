#include <stdio.h>

// About: Find Kth smallest element in two sorted arrays
// Approach : O(m+n)
// Algorithm : 1. Use two pointers to point to two arrays.
//             2. Increment P1 if Array[P1] < Array[P2] else increment P2 and store the max value
//             3. Repeat 1 till counter value == K
//             4. return result



// Function API
int get_ith_value(int* arr_one, int* arr_two, int size_one,int size_two, int n);

int main()
{

int arr_one[] = {2,6,7,8,9};
int arr_two[] = {5,18,34};
int res;

res = get_ith_value(arr_one,arr_two,5,3,7);

printf("%d",res);

}

int get_ith_value(int* arr_one, int* arr_two, int size_one,int size_two, int n){

    int i = 0;
    int j = 0;
    int counter = n;

    int result;

    while ((i<size_one) && (j < size_two) && (counter >= 0)) {

          if(arr_one[i] < arr_two[j]) {
            result = arr_one[j];
            i++;
          }
          else {
            result = arr_two[i];
            j++;
          }

          counter --;
    }

    if(counter == 0)
            return result;

    // If the arrays are unequal and scanning reaches end of one of the array.
    if (i<size_one)
        result = arr_one[i+counter];
    else
        result = arr_two[j+counter];

    return result;

}
