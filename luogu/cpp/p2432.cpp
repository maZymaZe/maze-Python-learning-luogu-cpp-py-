#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
string s,s1[610];
int l,l1[610],f[610];
int main(){
    memset(f,0x3f, sizeof(f));
    int n,t;
    cin>>n>>t;
    cin>>s;l=s.size();
    for(int i=0;i<n;i++){
        cin>>s1[i];l1[i]=s1[i].size();
    }
    f[0]=0;
    for(int i=0;i<l;i++){
        if(!i)f[i+1]=1;
        else f[i+1]=f[i]+1;
        for(int j=0;j<n;j++){
            int ll=i,ll1=l1[j]-1;
            while(ll>=0&&ll1>=0){
                if(s[ll]==s1[j][ll1])ll--,ll1--;
                else ll--;
            }
            if(ll1<0)f[i+1]=min(f[i+1],f[ll+1]+(i-ll-l1[j]));
        }
    }
    cout<<f[l];
    return 0;
}