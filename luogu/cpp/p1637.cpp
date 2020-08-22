#include <algorithm>
#include <cstdio>
#include<cstring>
using namespace std;
long long a[30006],mem[30006],ans=0;
int n, c[30006],a2[30006],l[30006],r[30006];
inline int lowbit(int x){ return x & (-x);}
inline void add(int p){
    while(p<=n)c[p]++,p+=lowbit(p);
}
inline int query(int p){
    int ret=0;
    while(p)ret+=c[p],p-=lowbit(p);
    return ret;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        mem[i] = a[i];
    }
    sort(a+1,a+1+n);
    int ttot=unique(a+1,a+1+n)-a;
    for(int i=1;i<=n;i++){
        a2[i]=lower_bound(a+1,a+ttot,mem[i])-a;
    }
    for(int i=1;i<=n;i++){
        l[i]=query(a2[i]-1);
        add(a2[i]);
    }
    memset(c, 0, sizeof(c));
    for(int i=n;i>0;i--){
        r[i]=query(n)-query(a2[i]);
        add(a2[i]);
    }
    for(int i=1;i<=n;i++)ans+=1LL*l[i]*r[i];
    printf("%lld\n",ans);
    return 0;
}