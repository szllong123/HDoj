/*************************************************************************
	> File Name: quick_sort.c
	> Author: szl
	> Mail: szllong@cqu.edu.cn 
	> Created Time: 2014/10/12 23:43:00
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef int cmp_type;
typedef int object_type;

int randomized_partition(int *a, int start_index, int end_index, int (*cmp)(cmp_type a, cmp_type b));
void myquick_sort(int *a, int start_index, int end_index, int (*cmp)(cmp_type a, cmp_type b));
int mycmp(cmp_type a, cmp_type b);
void myswap(int &a,int &b);
object_type arr[7] ={1, 5, 2, 4, 6, 9, 3};

int main(int argc, char *argv[])
{
	int i;
	for(i = 0; i < 7; i++){
		printf("%d\t", arr[i]);
	}
	myquick_sort(arr, 0, 6, mycmp);
	printf("\n");
	for(i = 0; i < 7; i++){
		printf("%d\t", arr[i]);
	}
	return 0;
}


void myquick_sort(int *a, int start_index, int end_index, int (*cmp)(cmp_type a, cmp_type b))
{
	int pivot = 0;
	if(start_index < end_index){
		pivot = randomized_partition(a, start_index, end_index, mycmp);
		myquick_sort(a, start_index, pivot-1, mycmp);
		myquick_sort(a, pivot+1, end_index, mycmp);
	}
}

int randomized_partition(int *a, int start_index, int end_index, int (*cmp)(cmp_type a, cmp_type b))
{
	int pivot = 0;
	srand(time(0));
	pivot = rand() % (end_index - start_index) + start_index;
	myswap(a[pivot], a[end_index]);
	int key = a[end_index];
	int i = start_index - 1;
	for(int j = i + 1; j < end_index; j++){
		if(cmp(a[j], key)){
			i++;
			myswap(a[i], a[j]);
		}
	}
	myswap(a[i+1], a[end_index]);
	return i + 1;
}


int mycmp(cmp_type a, cmp_type b)
{
	return a < b;
}

void myswap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

