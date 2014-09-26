/*************************************************************************
	> File Name: sum1002.c
	> Author: szl
	> Mail: szllong@cqu.edu.cn 
	> Created Time: 2014/9/26 18:35:15
 ************************************************************************/

#include <stdio.h>
#include <string.h>
void mysum(char a[], char b[], char sum[]);
void real_sum(char a[], char b[], int s_len, int l_len, char sum[]);
int main(int argc, char *argv[])
{
    int i = 0, n = 0;
    char a[1001] = {' '}, b[1001] = {' '};
    char sum[1005] = {' '};
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        memset(sum, 0, 1005);
        scanf("%s %s", a, b);
        printf("Case %d:\n", i);
        printf("%s + %s =", a, b);
        mysum(a, b, sum);
        if(i != n)
             printf("\n\n");
        else
            printf("\n");
    }
    return 0;
}

void mysum(char a[], char b[], char sum[])
{
    int a_len = 0, b_len = 0;
    a_len = strlen(a);
    b_len = strlen(b);
    if(a_len < b_len)
        real_sum(b, a, a_len, b_len, sum);
    else
        real_sum(a, b, b_len, a_len, sum);
}

void real_sum(char a[], char b[], int s_len, int l_len, char sum[])
{
    int flag = 0;
    int temp = 0;
    int i = l_len,j = s_len;
    for(i = l_len; i > 0; i--){
        if(j > 0){
            temp  = a[i - 1] + b[j -1] + flag - 96;
            j--;
        }else
            temp = a[i - 1] + flag - 48;

        if(temp >= 10)
            flag = 1;
        else
            flag = 0;

        temp = temp % 10;
        sum[i] = temp + 48;
    }
    if(flag == 1)
        sum[0] = 49;

    if(sum[0] == 0)
        printf(" ");
    else
        printf(" %c", sum[0]);

    for(i = 1; i <= l_len; i++){
        printf("%c", sum[i]);
    }

}

