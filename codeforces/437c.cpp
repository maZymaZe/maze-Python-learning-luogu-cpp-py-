#include<cstdio>
int min(int a, int b) { return a < b?a:b;}
int n,m,t1,t2,val[1024];
long long ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&t1,&t2);
        ans+=min(val[t1],val[t2]);
    }
    printf("%lld",ans);
    return 0;
}