#include<string>
#include<iostream>
using namespace std;
string  s;
const long long MOD= 1e9 + 7;
int T;
int main(){
    cin>>T;
    while(T--){
        int x;
        cin>>x;
        cin>>s;
        long long ans=s.size();
        for(int i=0;i<x;i++){
            if(s.size()>=x){
                ans=(ans+(long long)(ans-i-1+MOD)% MOD*(s[i]-'1'))% MOD;
            }
            else{
                if(s[i]=='2')s+=s.substr(i+1);
                if(s[i]=='3')s+=s.substr(i+1)+s.substr(i+1);
                ans=s.size();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}