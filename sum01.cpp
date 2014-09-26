#include <stdio.h>
int main(int argc, char *arcv[])
{
	int i = 0, n = 0, sum = 0;
	while(scanf("%d", &n) != EOF){
		for(i = 1; i <= n; i++){
			sum += i;
		}
		printf("%d\n", sum);
		printf("\n");
		sum = 0;
	}
	return 0;
}