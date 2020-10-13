#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
string op;
int l1=0,l2=0,n,dp[60][400]={0},a[60]={0},pa=0,x;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>op;
        scanf("%d",&x);
        if(op[0]=='r')a[++pa]=x%360;
        else if(op[0]=='l')a[++pa]=(720-x)%360;
        else if(op[0]=='f')l1+=x;
        else if(op[0]=='b') l2+=x;
    }
    dp[0][0]=1;
    for(int i=1;i<=pa;i++){
        for(int j=0;j<360;j++){
            dp[i][(j+a[i])%360]|=dp[i-1][j];
            dp[i][j]|=dp[i-1][j];
        }
    }
    int k=0;
    while((!dp[pa][180+k])&&(!dp[pa][180-k])){
        k++;
    }
    double tmp=2*l1*l2*cos(3.1415926535*k/180);
    double ans=sqrt((l1*l1+l2*l2)+tmp);
    printf("%.6lf",ans);
    return 0;
}