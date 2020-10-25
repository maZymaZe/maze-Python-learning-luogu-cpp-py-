#include<cstdio>
#include<cmath>
const double EPS=1e-7;
int n;
double l,r,a[19];
double f(double x){
    double ans=0;
    for(int i=n;i>=0;i--){
        ans=ans*x+a[i];
    }
    return ans;
}
int main(){
    scanf("%d%lf%lf",&n,&l,&r);
    for(int i=n;i>=0;i--)scanf("%lf",&a[i]);
    while(fabs(l-r)>EPS){
        double mid=(l+r)/2;
        if(f(mid+EPS)>f(mid-EPS))l=mid;
        else r=mid;
    }
    printf("%.5lf",r);
    return 0;
}