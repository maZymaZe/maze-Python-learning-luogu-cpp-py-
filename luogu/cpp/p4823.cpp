#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX=2009,INF=0x3f3f3f3f;
struct person{
    int a,b;
}p[NMAX];
bool cmp(const person&x,const person&y){
    return x.a+x.b<y.a+y.b||(x.a+x.b==y.a+y.b&&x.a<y.a);
}
int n,dp[NMAX],h;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].a,&p[i].b);
        dp[0]+=p[i].a;dp[i]=-INF;
    }
    
    scanf("%d",&h);
    sort(p+1,p+1+n,cmp);
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            if(dp[j-1]+p[i].b>=h)dp[j]=max(dp[j],dp[j-1]-p[i].a);
        }
    }
    for(int i=n;i>=0;i--){
        if(dp[i]>=0){
            printf("%d",i);
            break;
        }
    }
    return 0;
}