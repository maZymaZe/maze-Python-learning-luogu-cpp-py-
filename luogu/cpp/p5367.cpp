#include<cstdio>
const long long MOD=998244353;
int n,c[1000006],a[1000006],t;
long long jx,ans=1;
inline int lowbit(int x){ return x & (-x);}
inline void add(int p){while(p<=n)c[p]++,p+=lowbit(p);}
inline int query(int p){
    int ret=0;
    while(p)ret+=c[p],p-=lowbit(p);
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=n;i>0;i--){
        scanf("%d",&a[i]);
    }
    jx=1;
    for(int i=1;i<=n;i++){
        ans=(ans+jx*query(a[i]))% MOD;
        jx=jx*i%MOD;
        add(a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}