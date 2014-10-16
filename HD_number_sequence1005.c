/*************************************************************************
	> File Name: HD_number_sequence1005.c
	> Author: szl
	> Mail: szllong@cqu.edu.cn 
	> Created Time: 2014/10/2 23:57:59
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define mod_num 7

int main(int argc, char *argv[])
{
	int first_num, second_num, third_num;
	int A, B;
	int i;
	long n;
	int temp;
	while(1){
		scanf("%d %d %d", &A, &B, &temp);
		if(A == 0 && B == 0 && temp == 0)
			break;	
		n = temp % 49;

		first_num = 1, second_num = 1, third_num = 0;
		for(i = 2; i < n; i++){
			third_num = (A * second_num + B * first_num) % mod_num;
			first_num = second_num;
			second_num = third_num;
		}
		if(n == 1 || n == 2)
			printf("1\n");
		else
			printf("%d\n", third_num);
	}
	return 0;
}
