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

bool cmp_x(object_type &a, object_type &b);
bool cmp_y(object_type &a, object_type &b);
double find_min_dist_x(int start_index, int end_index);
double find_min_dist_y(int start_index, int end_index);
double get_distance_min2(object_type &ponint1, object_type &point2);
double min(double n1, double n2);

object_type point_x[length];
object_type point_y[length];

int main(int argc, char *argv[])
{
	int N;
	double min_dist;
	int counter_x = 0, counter_y = 0;
	double temp_x, temp_y;
	while(scanf("%d", &N) != EOF && N){
		counter_x = 0, counter_y = 0;
		temp_x = ENF, temp_y = ENF;
		memset(point_x, 0, length * sizeof(object_type));
		memset(point_y, 0, length * sizeof(object_type));
		for(int i = 0;i < N; i++){
			scanf("%lf %lf", &(point_x[i].x), &(point_x[i].y));
		}
		memcpy(point_y, point_x, N * sizeof(object_type));
		sort(point_x, point_x + N, cmp_x);
		sort(point_y, point_y + N, cmp_y);
		for(int i = 0; i < N; i++){
			if(temp_x == point_x[i].x)
				counter_x++;
			else{
				temp_x = point_x[i].x;
				counter_x = 0;
			}
			if(temp_y == point_y[i].y)
				counter_y++;
			else{
				temp_y = point_y[i].y;
				counter_y = 0;
			}
		}
		if(counter_x < counter_y){
			min_dist = find_min_dist_x(0, N - 1);
		}else{
			min_dist = find_min_dist_y(0, N - 1);
		}
		
		printf("%.2lf\n", min_dist / 2);
	}
	return 0;
}

inline double find_min_dist_x(int start_index, int end_index)
{
	double min_dis = ENF;
	for(int i = start_index; i < end_index; i++){
		for(int j = i + 1; j < end_index + 1; j++){
			if(point_x[j].x - point_x[i].x < min_dis){
				if(fabs(point_x[j].y - point_x[i].y) < min_dis){
					min_dis = min(get_distance_min2(point_x[i], point_x[j]), min_dis);
				}
			}else{
				break;
			}
		}
		
	}
	return min_dis;
}

inline double find_min_dist_y(int start_index, int end_index)
{
	double min_dis = ENF;
	for(int i = start_index; i < end_index; i++){
		for(int j = i + 1; j < end_index + 1; j++){
			if(point_y[j].y - point_y[i].y < min_dis){
				if(fabs(point_y[j].x - point_y[i].x) < min_dis){
					min_dis = min(get_distance_min2(point_y[i], point_y[j]), min_dis);
				}
			}else{
				break;
			}
		}
		
	}
	return min_dis;
}


inline double get_distance_min2(object_type &point1, object_type &point2)
{
	return sqrt(pow(point1.x - point2.x, 2.0) + pow(point1.y - point2.y, 2.0));
}

inline double min(double n1, double n2)
{
	if(n1 < n2)
		return n1;
	return n2;
}
bool cmp_x(object_type &a, object_type &b)
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