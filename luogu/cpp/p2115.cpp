#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 1e5 + 10;
const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;
int n, a[NMAX], sum;
bool check(double mid){
    double res=sum-mid*n,mx=-INF,s=0;
    for(int i=2;i<n; i++){
        s+=a[i]-mid;mx=max(mx,s);
        if(s<0.0)s=0;
    }
    return res-mx<=0;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sum += a[i];
    double l=0,r=1e4,mid;
    while(l+EPS<r){
        mid=l+(r-l)/2;
        if(check(mid))r=mid;
        else l=mid;
    }
    printf("%.3lf",l);
    return 0;
}