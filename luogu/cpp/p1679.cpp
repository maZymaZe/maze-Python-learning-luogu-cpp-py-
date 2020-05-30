#include<cstdio>
#define MMAX 103000
int min(int a,int b){return a<b?a:b;}
int c[19],dp[MMAX],v;
int main(){
    scanf("%d",&v);
    for(int i=1; i<=18; i++){
        c[i]=i*i*i*i;
    }
    for(int i=1;i<=v;i++){
        dp[i]=99999999;
        for(int j=1;j<19;j++){
            if(i>=c[j])dp[i]=min(dp[i],dp[i-c[j]]+1);
        }
    }
    printf("%d",dp[v]);
    return 0;
}