#include<cstdio>
int main() {
    double a,b,s,t1,t2;
    scanf("%lf%lf%lf",&s,&a,&b);
    t1=s/((a+b)+a*(b-a)/(a+b));
    t2=(b-a)*t1/(a+b);
    printf("%.6lf",2*t1+t2);
    return 0;
}