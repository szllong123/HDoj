/*************************************************************************
	> File Name: max_balloon_num.c
	> Author: szl
	> Mail: szllong@cqu.edu.cn 
	> Created Time: 2014/10/2 16:56:26
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ball{
	char ball_color[16];
	int ball_num;
};
struct ball ball_arr[100];
int current_color_num;

void insert_to_ball_arr(char *temp_color);

int main(int argc, char *argv[])
{
	int i;
	int ball_num;
	int max_num, max_num_index;
	char temp_color[16] = {""};
	while(1){
		scanf("%d", &ball_num);
		if(ball_num == 0)
			break;
		max_num = 0, current_color_num = 1;
		memset(ball_arr, 0, 100*sizeof(struct ball));
		for(i = 0; i < ball_num; i++){
			scanf("%s", temp_color);
			insert_to_ball_arr(temp_color);
		}
		for(i = 0; i < current_color_num; i++){
			if(max_num < ball_arr[i].ball_num){
				max_num = ball_arr[i].ball_num;
				max_num_index = i;
			}
		}
		printf("%s\n", ball_arr[max_num_index].ball_color);
	}
	return 0;
}

void insert_to_ball_arr(char *temp_color){
	int i;
	for(i = 0; i < current_color_num; i++){
		if(strcmp(ball_arr[i].ball_color, temp_color) == 0){
			ball_arr[i].ball_num++;
			return;
		}
	}
	if(i == current_color_num){
		strcpy(ball_arr[i].ball_color, temp_color);
		current_color_num++;
	}
}
