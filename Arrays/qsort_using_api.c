#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// About : Implement sorting using qsort API in stdlib for integer variables only

int cmpint (const void * a, const void * b);

int main()
{

int i;
int int_array[] = {10,5,6,2};

qsort(int_array,4,sizeof(int),cmpint);

//Sorted integer
for(i=0;i<4;i++)
    printf("%d\n",int_array[i]);

return 0;

}

//Compare integer
int cmpint (const void * a, const void * b) {
   return (*(int*)a - *(int*)b);
}
