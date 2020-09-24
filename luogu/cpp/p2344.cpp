#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX = 1e5+ 10;
const int MOD = 1e9 + 9;
inline int lowbit(int x){ return x & (-x);}
int n,sum[NMAX],s,sumsort[NMAX],tre[NMAX];
inline void add(int x,int val){
    while(x<=s){
        tre[x]=(tre[x]+val)%MOD;
        x+=lowbit(x);
    }
}
inline int query(int x){
    int ret=0;
    while(x>0){
        ret=(ret+tre[x])%MOD;
        x-=lowbit(x);
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&sum[i]);
        sum[i]+=sum[i-1];
        sumsort[i]=sum[i];
    }
    sort(sumsort,sumsort+1+n);
    s=unique(sumsort,sumsort+1+n)-sumsort;
    for(int i=0;i<=n;i++)sum[i]=lower_bound(sumsort,sumsort+s,sum[i])-sumsort+1;
    add(sum[0],1);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=query(sum[i]);
        add(sum[i],ans);
    }
    printf("%d\n",ans);
    return 0;
}
