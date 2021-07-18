#include<iostream>
#include<string>
using namespace std;
string s;
int n;
int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        int l=s.length();
        if(s[l-1]=='o')cout<<"FILIPINO"<<endl;
        if(s[l-1]=='u')cout<<"JAPANESE"<<endl;
        if(s[l-1]=='a')cout<<"KOREAN"<<endl;
    }
    return 0;
}