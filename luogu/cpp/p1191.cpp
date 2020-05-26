#include<string>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,ans={0},h[155]={0};

int main(){
    string s;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='W')h[j]+=1;
            else h[j]=0;
        }
        for(int j=n-1;j>=0;j--){
            if(s[j]=='B')continue;
            int v=h[j];
            for(int k=j;k>=0;k--){
                if(s[k]=='W'){
                    v=min(v,h[k]);
                    ans+=v;
                }
                else break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}