/*************************************************************************
	> File Name: HD_min_dist_point1007.cpp
	> Author: szl
	> Mail: szllong@cqu.edu.cn 
	> Created Time: 2014/10/14 12:46:37
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#define length 100003
#define ENF 65535.00
using namespace std;

struct point{
	double x;
	double y;
};
typedef struct point object_type;

int randomized_partition(object_type *a, int start_index, int end_index, bool (*cmp)(object_type &a, object_type &b));
void myquick_sort(object_type *a, int start_index, int end_index, bool (*cmp)(object_type &a, object_type &b));
void myswap(object_type &a,object_type &b);

bool mycmp(object_type &a, object_type &b);
bool cmp_y(object_type &a, object_type &b);
double find_min_dist(int start_index, int end_index);
double find_mid_min_dist(int start_index, int mid_index,int end_index, double temp_min1);
double get_distance_min2(object_type &ponint1, object_type &point2);
double get_distance_min3(object_type &point1, object_type &point2, object_type &point3);
double min(double n1, double n2);

object_type point[length];
object_type assist_arr[length];

int main(int argc, char *argv[])
{
	int N;
	double min_dist;
	while(scanf("%d", &N) != EOF && N){
		for(int i = 0;i < N; i++){
			scanf("%lf %lf", &(point[i].x), &(point[i].y));
		}
//		myquick_sort(point, 0, N-1, mycmp);
		sort(point, point + N, mycmp);
		min_dist = find_min_dist(0, N - 1);
		printf("%.2lf\n", min_dist / 2);
	}
	return 0;
}

double find_min_dist(int start_index, int end_index)
{
	double min_dis = 0;
	if(start_index == end_index)
		return 0;
	else if(end_index - start_index == 1)
		min_dis = get_distance_min2(point[start_index], point[end_index]);
	else if(end_index - start_index == 2)
		min_dis = get_distance_min3(point[start_index], point[start_index + 1], point[end_index]);
	else{
		int mid = (start_index + end_index) / 2;
		double left_min, right_min, temp_min;
		left_min = find_min_dist(start_index, mid);
		right_min = find_min_dist(mid + 1, end_index);
		temp_min = min(left_min, right_min);
		min_dis = find_mid_min_dist(start_index, mid, end_index, temp_min);
	}
	return min_dis;
}

double find_mid_min_dist(int start_index, int mid_index,int end_index, double temp_min1)
{
	int temp_index = 0;
	double temp_min2 = ENF, temp_min3 = temp_min1;
	double left_bound, right_bound;
	left_bound = point[mid_index].x - temp_min1;
	right_bound = point[mid_index].x + temp_min1;
	for(int i = start_index; i <= mid_index; i++){
		if(left_bound <= point[i].x){
			assist_arr[temp_index].x = point[i].x;
			assist_arr[temp_index].y = point[i].y;
			temp_index++;
		}
	}
	for(int i = mid_index + 1; i <= end_index; i++){
		if(point[i].x <= right_bound){
			assist_arr[temp_index].x = point[i].x;
			assist_arr[temp_index].y = point[i].y;
			temp_index++;
		}
	}
//	myquick_sort(assist_arr, 0, temp_index -1, cmp_y);
	sort(assist_arr, assist_arr + temp_index, cmp_y);
	for(int i = 0; i < temp_index; i++){
		for(int j = 1; (j <= 7) && (i + j < temp_index); j++){
				temp_min2 = get_distance_min2(assist_arr[j + i], assist_arr[i]);
				if(temp_min3 > temp_min2){
					temp_min3 = temp_min2;
				}
		}
	}
	return temp_min3;
		

}

double get_distance_min2(object_type &point1, object_type &point2)
{
	return sqrt(pow(point1.x - point2.x, 2.0) + pow(point1.y - point2.y, 2.0));
}

double get_distance_min3(object_type &point1, object_type &point2, object_type &point3)
{
	double dis1, dis2, dis3, min_dis;
	dis1 = get_distance_min2(point1, point2);
	dis2 = get_distance_min2(point2, point3);
	dis3 = get_distance_min2(point1, point3);
	min_dis = dis1 < dis2 ? dis1 : dis2;
	min_dis = min_dis < dis3 ? min_dis : dis3;
	return min_dis;
}

double min(double n1, double n2)
{
	if(n1 < n2)
		return n1;
	return n2;
}
bool mycmp(object_type &a, object_type &b)
{
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}
bool cmp_y(object_type &a, object_type &b)
{
	if(a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}


void myquick_sort(object_type *a, int start_index, int end_index, bool (*cmp)(object_type &a, object_type &b))
{
	int pivot = 0;
	if(start_index < end_index){
		pivot = randomized_partition(a, start_index, end_index, mycmp);
		myquick_sort(a, start_index, pivot-1, mycmp);
		myquick_sort(a, pivot+1, end_index, mycmp);
	}
}

int randomized_partition(object_type *a, int start_index, int end_index, bool (*cmp)(object_type &a, object_type &b))
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


void myswap(object_type &a,object_type &b)
{
	object_type temp;
	temp=a;
	a=b;
	b=temp;
}

