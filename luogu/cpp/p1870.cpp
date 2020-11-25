#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,a,d,t,v;
double pre=0,res;
int main(){
    scanf("%d%d%d",&n,&a,&d);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&t,&v);
        if(2*d>=(1.0*v/a)*v){
            res=(double)t+1.0*(d-0.5*v*(1.0*v/a))/v+(1.0*v/a);
        }else res=sqrt(2.0*d/a)+t;
        if(res>pre)pre=res;
        else res=pre;
        res*=10000;res=floor(res);res/=10000;
        printf("%.4lf\n",res);
    }
    return 0;
}