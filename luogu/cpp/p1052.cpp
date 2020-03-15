#include<cstdio>
#include<algorithm>
using namespace std;
int p,w=0,c=0,l,s,t,m,d[120],mp[10501]={0},dp[10501]={0};
int main(){
    scanf("%d%d%d%d",&l,&s,&t,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&d[i]);
    }
    sort(d+1,d+1+m);
    if(s==t){
        for(int i=1;i<=m;i++){
            if(d[i]%s==0)c++;
        }
        printf("%d",c);
    }
    else{
        for(int i=1;i<=m;i++){
            if(d[i]-w>90){
                p+=90;
                mp[p]=1;
                w=d[i];
            }
            else{
                p+=d[i]-w;
                mp[p]=1;
                w=d[i];
            }
        }
        for(int i=1;i<=s-1;i++)dp[i]=-1;
        for(int i=1;i<=p+100;i++){
            if(i>=s){
                dp[i]=999;
                for(int j=s;j<=t;j++)
                if(i-j>=0&&dp[i-j]!=-1){
                    dp[i]=min(dp[i],dp[i-j])+mp[i];
                }
            }
        }
        printf("%d",dp[p+100]);
    }
    return 0;
}