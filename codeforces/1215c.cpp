#include<string>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,ca,cb;
string s,t;
vector<int> t1,t2,ans1,ans2;
int main(){
    cin>>n>>s>>t;
    for(int i=0;i<n;i++){
        if(t[i]==s[i]) continue;
        if(t[i]=='a')ca++,t1.push_back(i+1);
        if(s[i]=='a')cb++,t2.push_back(i+1);
    }
    if((ca+cb)%2==1){
        printf("-1\n");
        return 0;
    }
    while(t1.size()>1){
        ans1.push_back(t1.back());
        t1.pop_back();
        ans2.push_back(t1.back());
        t1.pop_back();
    }
    while(t2.size()>1){
        ans1.push_back(t2.back());
        t2.pop_back();
        ans2.push_back(t2.back());
        t2.pop_back();
    }
    if(t1.size()==1){
        ans1.push_back(t1[0]);
        ans2.push_back(t1[0]);
        ans1.push_back(t1[0]);
        ans2.push_back(t2[0]);
    }
    int len=ans1.size();
    printf("%d\n", len);
    for(int i=0; i<len;i++){
        printf("%d %d\n",ans1[i],ans2[i]);
    }
    return 0;
}