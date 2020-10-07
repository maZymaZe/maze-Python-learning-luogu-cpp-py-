#include<cstdio>
long long a,b,k,n,m,y[1005];
int main(){
    scanf("%lld%lld%lld%lld%lld", &a, &b, &k, &n, &m);
    y[1]=1;
    for(int i=1;i<=k+1;i++){
        y[i]=1;
        for(int j=i-1;j>1;j--)y[j]+=y[j-1],y[j]%=10007;
    }
    long long ans=y[n+1];
    for(int i=1;i<=n;i++)ans=(ans*a)%10007;
    for(int i=1;i<=m;i++)ans=(ans*b)%10007;
    printf("%lld",ans);
    return 0;
}