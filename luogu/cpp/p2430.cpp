#include<cstdio>
#define MMAX 13000
#define NMAX 5200
int max(int a,int b){
    return a > b ? a : b;
}
int c[NMAX],w[NMAX],dp[MMAX],n,v,b1,b2,b,mp[NMAX];
int main(){
    scanf("%d%d",&b1,&b2);
    b=b2/b1;

    scanf("%d%d",&n,&b1);
    for(int i=0;i<b1;i++){
        scanf("%d",&b2);
        mp[i+1]=b*b2;
    }
    for(int i=0; i<n; i++){
        scanf("%d%d",&c[i],&w[i]);
        c[i]=mp[c[i]];
    }
    scanf("%d",&v);
    for(int i=0; i<n; i++){
        for(int j=v;j>=c[i];j--){
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    printf("%d",dp[v]);
    return 0;
}