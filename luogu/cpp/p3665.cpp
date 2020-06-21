#include<cstdio>
#define ll long long
ll c[200005],n,q,s,t,t1=0,t2=0,t3,sum=0,tot=0;
int main(){
    scanf("%lld%lld%lld%lld",&n,&q,&s,&t);
    for(int i=0;i<=n;i++){
        scanf("%lld",&t1);
        c[i] = t1-t2;
        t2=t1;
    }
    for(int i=1;i<=n;i++){
        tot+=(c[i]>=0)?(-s*c[i]):(-t*c[i]);
    }
    for(int i=1;i<=q; i++){
        scanf("%lld%lld%lld",&t1,&t2,&t3);
        t2++;
        tot-=(c[t1]>=0)?(-s*c[t1]):(-t*c[t1]);
        if(t2<=n)tot-=(c[t2]>=0)?(-s*c[t2]):(-t*c[t2]);
        c[t1]+=t3;c[t2]-=t3;
        tot+=(c[t1]>=0)?(-s*c[t1]):(-t*c[t1]);
        if(t2<=n)tot+=(c[t2]>=0)?(-s*c[t2]):(-t*c[t2]);
        printf("%lld\n", tot);
    }
    return 0;
}