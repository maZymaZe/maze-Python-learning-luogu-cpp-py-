#include<cstdio>
int max(int a,int b){ return a > b ? a : b;}
int n,dp[1002]={0},v[1002]={0},ans=0;
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        v[i]=-i;
        for(int j=1;j*j<=i;j++){
            if(i%j==0)v[i]+=j+i/j;
            if(j*j==i)v[i]-=j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            dp[j]=max(dp[j],dp[j-i]+v[i]);
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}