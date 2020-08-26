#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int dp[2005][2005]={0};
int main(){
    string a,b;
    int k,la,lb;
    cin>>a>>b>>k;
    la=a.size(),lb=b.size();
    memset(dp,0x3f, sizeof(dp));
    for(int i=0;i<=la;i++){
        dp[i][0]=k*i;
    }
    for(int i=0;i<=lb;i++){
        dp[0][i]=k*i;
    }
    for(int i=0;i<la;i++){
        for(int j=0;j<lb;j++){
            dp[i+1][j+1]=min(dp[i][j]+abs(a[i]-b[j]),min(dp[i+1][j],dp[i][j+1])+k);
        }
    }
    cout<<dp[la][lb]<<endl;
    return 0;
}