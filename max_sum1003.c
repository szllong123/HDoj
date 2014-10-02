/*************************************************************************
	> File Name: max_sum1003.c
	> Author: szl
	> Mail: szllong@cqu.edu.cn 
	> Created Time: 2014/10/1 9:48:24
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[])
{
	int begin_index = 0, end_index = 0, temp_index = 0;
	int line_num = 0, N = 0;
	int temp = 0;
	int max_sum = -1001, current_sum = 0;
	int i = 0, j = 0;
	scanf("%d", &line_num);
	for(j = 0; j< line_num; j++){
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%d",&temp);
			current_sum += temp;
			if(max_sum < current_sum){
				max_sum = current_sum;
				begin_index = temp_index;
				end_index = i;
			}
			if(current_sum < 0){
				temp_index = i + 1;
				current_sum = 0;
			}
		}
		printf("Case %d:\n", j + 1);
		printf("%d %d %d\n", max_sum, begin_index + 1, end_index + 1);
		max_sum = -1001;
		current_sum = 0;
		temp_index = 0;
		if(j != line_num -1)
			printf("\n");
	}
	return 0;
}
