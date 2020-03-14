#include<cstdio>
int n,ls[210],dp[201][201];
int dfs(int l,int r){
    if(l==r)return 0;
    if(dp[l][r])return dp[l][r];
    else{
        int tt,mx=0;
        for(int i=l;i<r;i++){
            tt=dfs(l,i)+dfs(i+1,r)+ls[l-1]*ls[r]*ls[i];
            if(tt>mx)mx=tt;
        }
        if(r<=n)dp[l+n][r+n]=mx;
        return dp[l][r]=mx;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&ls[i]);
        ls[i+n]=ls[i];
    }
    ls[0]=ls[n];ls[2*n+1]=ls[1];
    int ans=0,tt;
    for(int i=1;i<=n;i++){
        tt=dfs(i,i+n-1);
        if(tt>ans)ans=tt;
    }
    printf("%d",ans);
    return 0;
}