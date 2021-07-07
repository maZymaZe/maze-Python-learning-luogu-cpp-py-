#include<cmath>
#include<cstdio>
const int NMAX=1e5 + 10;
double x[NMAX],y[NMAX];
const double EPS=1e-5;
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&x[i],&y[i]);
    }
    if(n&1){
        printf("NO\n");
        return 0;
    }
    int op=n/2+1;
    double xx=(x[1]+x[op])/2,yy=(y[1]+y[op])/2;
    bool flag=0;
    int t=n/2;
    for(int i=1;i<=t;i++){
        double tx=(x[i]+x[op])/2,ty=(y[i]+y[op])/2;
        op++;
        if(fabs(tx-xx)>EPS||fabs(ty-yy)>EPS){
            flag=1;break;
        }
    }
    if(flag)printf("NO\n");
    else printf("YES\n");
    return 0;
}