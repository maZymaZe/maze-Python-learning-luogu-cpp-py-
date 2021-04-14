#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX=4e5+ 10,MOD=92084931;
int n,m,a[NMAX],s[NMAX],c[NMAX],t[NMAX],ans=0;
int lowbit(int x){return x & (-x);}
void add(int pos){
    while(pos<NMAX){
        c[pos]++;
        pos+=lowbit(pos);
    }
}
int query(int pos){
    int ret=0;
    while(pos){
        ret+=c[pos];
        pos-=lowbit(pos);
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]-=m;
        s[i]=s[i - 1]+a[i];
        t[i]=s[i];
    }
    sort(t,t+n+1);
    auto lim =unique(t,t+n+1);
    for(int i=0;i<=n;i++){
        s[i]=lower_bound(t,lim,s[i])-t+1;
    }
    for(int i=0;i<=n;i++){
        ans=(ans+query(s[i]-1))% MOD;
        add(s[i]);
    }
    printf("%d\n",ans);
    return 0;
}