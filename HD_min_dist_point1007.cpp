/*************************************************************************
	> File Name: HD_min_dist_point1007.cpp
	> Author: szl
	> Mail: szllong@cqu.edu.cn 
	> Created Time: 2014/10/14 12:46:37
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define length 10003
using namespace std;

struct point{
	double x;
	double y;
};
typedef struct point object_type;

int randomized_partition(object_type *a, int start_index, int end_index, int (*cmp)(object_type a, object_type b));
void myquick_sort(object_type *a, int start_index, int end_index, int (*cmp)(object_type a, object_type b));
int mycmp(object_type a, object_type b);
void myswap(object_type &a,object_type &b);
object_type point[length];


int main(int argc, char *argv[])
{
	int N;
	while(scanf("%d", &N) != EOF && N){
		for(int i = 0;i < N; i++){
			scanf("%lf %lf", &(point[i].x), &(point[i].y));
		}
		myquick_sort(point, 0, N - 1, mycmp);
		for(int i = 0;i < N; i++){
			printf("%.2lf %.2lf\n", (point[i].x), (point[i].y));
		}
	}
	return 0;
}

void myquick_sort(object_type *a, int start_index, int end_index, int (*cmp)(object_type a, object_type b))
{
	int pivot = 0;
	if(start_index < end_index){
		pivot = randomized_partition(a, start_index, end_index, mycmp);
		myquick_sort(a, start_index, pivot-1, mycmp);
		myquick_sort(a, pivot+1, end_index, mycmp);
	}
}

int randomized_partition(object_type *a, int start_index, int end_index, int (*cmp)(object_type a, object_type b))
{
	int pivot = 0;
	srand(time(0));
	pivot = rand() % (end_index - start_index) + start_index;
	myswap(a[pivot], a[end_index]);
	object_type key = a[end_index];
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


int mycmp(object_type a, object_type b)
{
	return a.x < b.x;
}

void myswap(object_type &a,object_type &b)
{
	object_type temp;
	temp=a;
	a=b;
	b=temp;
}
