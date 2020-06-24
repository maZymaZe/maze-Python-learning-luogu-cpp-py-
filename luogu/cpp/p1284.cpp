#include<cstdio>
#include<cmath>
int dp[810][810],n,s[50],tot;
double ans=-1,p;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&s[i]),tot+=s[i];
    p=1.0*tot/2;
    dp[0][0]=1;
    for(int k=1;k<=n;k++){
        for(int i=800;i>=0;i--){
            for(int j=800;j>=0;j--){
                if(i>=s[k])dp[i][j]|=dp[i-s[k]][j];
                if(j>=s[k])dp[i][j]|=dp[i][j-s[k]];
            }
        }
    }
    for(int a=800;a>=0;a--){
        for(int b=800;b>=0;b--){
            int c=tot-a-b;
            if(c>0&&dp[a][b])
            if(a+b>c&&a+c>b&&b+c>a){
                double res=sqrt((p-a)*(p-b)*(p-c)*p);
                if(res>ans)ans=res;
            }
        }
    }
    if(ans<0)printf("-1");
    else{
        ans*=100;
        printf("%d",(int)(ans));
    }
    return 0;
}
