#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,c[10],u[8][8],ans=0,l[100],r[100];
void ck(){
    memset(u,0,sizeof(u));
    int tot=0;
    for(int i=1;i<=m;i++){
        if(!u[c[l[i]]][c[r[i]]]){
            u[c[l[i]]][c[r[i]]]=u[c[r[i]]][c[l[i]]]=1;
            tot++;
        }
    }
    ans=max(tot,ans);
}
void dfs(int pos){
    if(pos>n){
        ck();
        return;
    }
    for(int i=1;i<=6;i++){
        c[pos]=i;
        dfs(pos+1);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
    }
    dfs(1);
    cout<<ans<< endl;
    return 0;
}