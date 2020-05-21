#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXLEN 12000000
char cg[MAXLEN*2];
int p[MAXLEN*2];
using namespace std;
int main(){
    string s;
    cin>>s;
    
    int ml,mr,l=s.size(),ll;
    cg[0]='*';
    for(int i=1;i<=l;i++){
        cg[(i << 1)-1]='#';
        cg[(i << 1)]=s[i-1];
    }
    cg[(l <<1)+1]='#';
    ll=2*l+1;
    int mid=1,mx=1,ans=-1;
    for(int i=1;i<=ll;i++){
        if(i<mx)p[i]=min(mx-i,p[2*mid-i]);
        else p[i]=1;
        while(cg[i-p[i]]==cg[i+p[i]])p[i]++;
        if(mx<i+p[i]){
            mid=i;
            mx=i+p[i];
        }
        if(p[i]-1>ans){
            ans=p[i]-1;
            ml=i-p[i]+1;mr=i+p[i]-1;
        }
    }
    printf("%d",ans);
    string tmp;
    for(int i=ml;i<=mr;i++)if(cg[i]!='#')tmp+=cg[i];
    cout<<tmp;
    return 0;
}