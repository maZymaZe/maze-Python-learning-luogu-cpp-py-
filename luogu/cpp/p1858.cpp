#include<cstdio>
int dp[5000][60]={0},v[300],w[300],n,k,V,t[60];
int main(){
    scanf("%d%d%d", &k,&V,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d", &w[i], &v[i]);
    }
    for(int i=0;i<=V;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=-99999999;
        }
    }
    dp[0][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=V;j>=w[i];j--){
            if(dp[j-w[i]][1]>=0){
                int p1=1,p2=1;
                for(int u=1;u<=k;u++){
                    t[u]=dp[j][u];
                    if(dp[j-w[i]][p2]+v[i]>t[p1]){
                        dp[j][u]=dp[j-w[i]][p2++]+v[i];
                    }
                    else dp[j][u]=t[p1++];
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        ans+=dp[V][i];
    }
    printf("%d\n",ans);
    return 0;
}