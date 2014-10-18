#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
struct room{
    double cat_food;
    double java_bean;
    double cat_bean;
};
bool comp(struct room &a, struct room &b);
int main(int argc, char *argv[])
{
    int N;
    double M;
    struct room i_room[1000];
    double total;
    while(scanf("%lf %d", &M, &N) != EOF && N != -1 && M != -1){
        total = 0.0;
        for(int i = 0; i < N; i++){
            scanf("%lf %lf", &i_room[i].java_bean, &i_room[i].cat_food);
            i_room[i].cat_bean = i_room[i].java_bean / i_room[i].cat_food;
        }
        sort(i_room, i_room + N, comp);
        for(int i = 0; i < N; i++){
            if(M > i_room[i].cat_food){
                total += i_room[i].java_bean;
                M -= i_room[i].cat_food;
            }else{
                total += M * i_room[i].cat_bean;
                break;
            }
        }
        printf("%.3lf\n", total);
    }
    return 0;
}

bool comp(struct room &a, struct room &b)
{
    return a.cat_bean > b.cat_bean;
}