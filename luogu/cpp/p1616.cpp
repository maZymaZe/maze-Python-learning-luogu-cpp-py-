#include<cstdio>
int max(int a,int b){
    if(a>b)return a;
    else return b;
}
int dp[100005],n,v[10005],p[10005],m,ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&p[i],&v[i]);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j>=p[i])
            dp[j]=max(dp[j],dp[j-p[i]]+v[i]);
        }
    }
    for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
    printf("%d",ans);
    return 0;
}