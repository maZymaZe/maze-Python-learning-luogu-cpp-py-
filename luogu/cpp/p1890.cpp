#include<cstdio>
int n,m,a[1001]={0},dp[1001][1001]={0},l,r;
int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&dp[i][i]);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            dp[j][j+i]=gcd(dp[j][j+i-1],dp[j+i][j+i]);
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&l,&r);
        printf("%d\n",dp[l][r]);
    }
    return 0;
}