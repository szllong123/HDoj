/*************************************************************************
	> File Name: HD_happy_tick.cpp
	> Author: szl
	> Mail: szllong@cqu.edu.cn 
	> Created Time: 2014/10/16 22:03:14
 ************************************************************************/

#include<stdio.h>
double vsm = 59.0 / 10,vsh = 719.0 / 120,vmh = 11.0 / 120,tsm = 360.0 / vsm,tsh = 360.0 / vsh,tmh = 360.0 / vmh;
double b1,b2,b3,e1,e2,e3;
double total,angle,start,ended;
double max(double a, double b){
	return a > b ? a : b;
}
double min(double a, double b){
	return a > b ? b : a;
}
int main()
{
	while(scanf("%lf",&angle),angle !=  -1){
		total = 0;
		b3 = angle / vmh;
		e3 = (360 - angle) / vmh;
		b1 = angle / vsm;
		e1 = (360 - angle) / vsm;
		b2 = angle / vsh;
		e2 = (360 - angle) / vsh;
		while(b3 < 43200){
			while(b1 < e3){
				while(b2 < e3&&b2 < e1){
					start = max(max(b1, b2), b3);
					ended = min(min(e1, e2), e3);
					total +=  (ended - start > 0) ? ended - start : 0;
					b2 = b2 + tsh;
					e2 = e2 + tsh;
				}
				b2 = b2 - tsh;
				e2 = e2 - tsh;
				b1 = b1 + tsm;
				e1 = e1 + tsm;
			}
			b1 = b1 - tsm;
			e1 = e1 - tsm;
			b3 = b3 + tmh;
			e3 = e3 + tmh;
		}
		printf("%.3lf\n",total / 432);
	}
	return 0;
}
