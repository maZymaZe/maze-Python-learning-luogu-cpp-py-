#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
const int NMAX= 1e5 + 10;
int n,a[NMAX],g[3],c[NMAX],id[NMAX];
bool ck(){
    c[id[1]]=1;
    g[1]=a[id[1]];
    c[id[2]]=2;
    g[2]=a[id[2]];
    for(int i=3;i<=n;i++){
        if(a[id[i]]%g[1]==0){
            c[id[i]]=2;
            g[2]=__gcd(g[2],a[id[i]]);
        }else{
            c[id[i]]=1;
            g[1]=__gcd(g[1],a[id[i]]);
        }
    }
    return g[1]==1&&g[2]==1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        id[i]=i;
    }
    int T=min(2000,(int)(1e8/20/n)),f=0;
    while(T--){
        random_shuffle(id+1,id+1+n);
        f=ck();
        if(f){
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++){
                printf("%d ",c[i]);
            }
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}