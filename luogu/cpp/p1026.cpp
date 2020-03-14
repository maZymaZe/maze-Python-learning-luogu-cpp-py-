#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string ls,wd[7];
int ans[201][201][41]={0};
int p,k,n,len,rs;
int dfs(int head,int tail,int cut){
    if(ans[head][tail][cut])return ans[head][tail][cut];
    else if(cut==0){
        string t=ls.substr(head,tail-head);
        int f=0,cnt=0;
        for(int i=0;i<tail-head;i++){
            f=0;
            for(int j=0;j<n;j++){
                if(tail-head-i>=wd[j].size()){
                    int fg=1;
                    for(int k=0;k<wd[j].size();k++){
                        if(t[i+k]!=wd[j][k]){
                            fg=0;
                            break;
                        }
                    }
                    if(fg==1){
                        f=1;
                    }
                 
                    if(f==1){
                        cnt++;
                        break;
                    }
                }
            }
        } 
        return ans[head][tail][cut]=cnt;
    }
    else{
        int mx=0,tt;
        for(int i=head;i<tail-cut;i++){
            tt=dfs(head,i+1,0)+dfs(i+1,tail,cut-1);
            if(tt>mx)mx=tt;
        }
        return ans[head][tail][cut]=mx;
    }
}
int main(){
    cin>>p>>k;
    cin>>ls;
    string t;
    for(int i=1;i<p;i++){
        cin>>t;
        ls=ls+t;
    }
    len=p*20;
    cin>>n;
    for(int i=0;i<n;i++)cin>>wd[i];
    rs=dfs(0,len,k-1);
    printf("%d",rs);
    return 0;
}