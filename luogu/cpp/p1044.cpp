#include<cstdio>
int dp[20][20]={0};
int dfs(int a,int b){
    if(dp[a][b])return dp[a][b];
    if(a==0)return 1;
    if(b)dp[a][b]+=dfs(a,b-1);
    dp[a][b]+=dfs(a-1,b+1);
    return dp[a][b];
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",dfs(n,0));
    return 0;
}