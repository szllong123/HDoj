/*************************************************************************
	> File Name: HD_elevator1008.cpp
	> Author: szl
	> Mail: szllong@cqu.edu.cn 
	> Created Time: 2014/10/17 12:42:29
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
	int N, pre_floor, cur_floor, pass_floors, total_time;
	while(scanf("%d", &N) != EOF && N != 0){
		pre_floor = 0;
		total_time = 0;
		pass_floors = 0;
		for(int i = 0; i < N; i++){
			scanf("%d", &cur_floor);
			pass_floors = cur_floor - pre_floor;
			pre_floor = cur_floor;
			if(pass_floors > 0){
				total_time += 6 * pass_floors + 5;
			}else{
				total_time += 4 * (-pass_floors) + 5;
			}
		}
		printf("%d\n", total_time);
	}
	return 0;
}
