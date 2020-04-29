#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int dp[51][51];
int main(){
    string s;
    cin>>s;
    int len=s.size();
    for(int i=0; i<len;i++)dp[i][i]=1;
    for(int l=2;l<=len;l++){
        for(int b=0;b<=len-l;b++){
            if(s[b]==s[b+l-1]){
                dp[b][l+b-1]=min(dp[b][l+b-2],dp[b+1][l+b-1]);
            }
            else{
                dp[b][l+b-1]=99999999;
                for(int i=1;i<l;i++){
                    dp[b][l+b-1]=min(dp[b][l+b-1],dp[b][b+i-1]+dp[b+i][l+b-1]);
                }
            }
        }
    }
    cout<<dp[0][len-1]<<endl;
    return 0;
}