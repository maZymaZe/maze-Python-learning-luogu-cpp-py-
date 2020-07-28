#include<string>
#include<iostream>
using namespace std;
int max(int a,int b){ return a > b ? a : b;}
char s[1004];
string s1;
int dp[1004][1004];
int main(){
    cin>>s1;
    int l=s1.size();
    for(int i=0; i<l; i++){
        s[i]=s1[l-i-1];
    }
    string s2(s);
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            if(s1[i]==s2[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }
            else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    cout<<l-dp[l][l]<<endl;
    return 0;
}