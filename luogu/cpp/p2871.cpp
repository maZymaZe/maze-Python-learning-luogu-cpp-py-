#include<cstdio>
#define MMAX 13000
#define NMAX 3500
int max(int a,int b){
    return a > b ? a : b;
}
int c[NMAX],w[NMAX],dp[MMAX],n,v;
int main(){
    scanf("%d%d",&n,&v);
    for(int i=0; i<n; i++){
        scanf("%d%d",&c[i],&w[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=v;j>=c[i];j--){
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    printf("%d",dp[v]);
    return 0;
}