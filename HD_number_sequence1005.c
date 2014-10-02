/*************************************************************************
	> File Name: HD_number_sequence1005.c
	> Author: szl
	> Mail: szllong@cqu.edu.cn 
	> Created Time: 2014/10/2 23:57:59
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[])
{
	int first_num, second_num, third_num;
	int A, B;
	int i, n;
	while(1){
		scanf("%d %d %d", &A, &B, &n);
		if(A == 0 && B == 0 && n == 0)
			break;
		first_num = 1, second_num = 1, third_num = 0;
		for(i = 2; i < n; i++){
			third_num = (A * second_num + B * first_num) % 7;
			first_num = second_num;
			second_num = third_num;
		}
		printf("%d\n", third_num);
	}
	return 0;
}
