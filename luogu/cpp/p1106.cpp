#include<list>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main(){
    list<int> ls;
    string s;
    int t,k;
    cin>>s>>k;
    for(int i=0;i<s.size();i++){
        ls.push_back((int)(s[i]-'0'));
    }
    for(int i=1;i<=k;i++){
        auto j=ls.begin();
        
        while(j!=ls.end()){
            auto r=j;j++;
            if((*r)>(*(j))){
                ls.erase(r);
                break;
            }
            if(j==ls.end()){
                ls.erase(r);break;
            }
        }
    }
    auto e=ls.begin();
    t=0;
    while(e!=ls.end()){
        if((*e)!=0){
            t=1;
            cout<<(*e);
        }
        else if(t==1)cout<<0;
        e++;
    }
    if(t==0)cout<<0;
    return 0;
}