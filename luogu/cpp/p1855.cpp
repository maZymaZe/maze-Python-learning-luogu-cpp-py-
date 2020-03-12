#include<cstdio>
int max(int a,int b){
    if(a>b)return a;
    else return b;
}
int dp[201][201]={0},n,t[101],m[101],lt,lm;
int main(){
    scanf("%d%d%d",&n,&lm,&lt);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&m[i],&t[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=lm;j>=m[i];j--){
            for(int k=lt;k>=t[i];k--){
                dp[j][k]=max(dp[j][k],dp[j-m[i]][k-t[i]]+1);
            }
        }
    }
    printf("%d",dp[lm][lt]);
    return 0;
}