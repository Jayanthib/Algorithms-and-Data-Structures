#include<stdio.h>

// About : Sample code to illustrate usage of function pointers

void task_one(int count);
void task_two(int count);
void task_three(int count);

void trigger_function(void (*function_ptr)(int),int);

int main(){

trigger_function(task_one,10);
trigger_function(task_two,20);
trigger_function(task_three,30);

}

void trigger_function(void (*function_ptr)(int), int count){
	function_ptr(count);
}
void task_one(int a){
	printf("I am %d\n",a);
}

void task_two(int count){
	printf("I am %d\n",count);
}

void task_three(int count){
	printf("I am %d\n",count);
}