#include<stack>
#include<string>
#include<iostream>
using namespace std;
string s;
stack<char> t;
int ans = 0,l;
int main(){
    cin>> s;
    l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]=='('){
            t.push('(');
        }else{
            if(t.empty()){
                t.push('(');ans++;
            }else t.pop();
        }
    }
    cout<<ans+t.size()/2<<endl;
    return 0;
}