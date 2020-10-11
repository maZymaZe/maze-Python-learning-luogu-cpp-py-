#include <cstdio>
const int NMAX=2e5+ 10;
int n,m,w[NMAX],l[NMAX],r[NMAX],cnt[NMAX];
long long s,v[NMAX],y,sum[NMAX],ans,mi=0x3f3f3f3f3f3f3f3f;
int left=0,right=1e6+1,mid;
void check(){
    y=0;
    for(int i=1;i<=n;i++){
        if(w[i]>=mid)sum[i]=sum[i-1]+v[i],cnt[i]=cnt[i-1]+1;
        else sum[i]=sum[i - 1],cnt[i]=cnt[i - 1];
    }
    for(int i=1;i<=m;i++){
        y+=(sum[r[i]]-sum[l[i]-1])*(cnt[r[i]]-cnt[l[i]-1]);
    }
    ans=s-y;
    if(ans<0)ans=-ans;
    if(ans<mi)mi=ans;
}

int main(){
    scanf("%d%d%lld",&n,&m,&s);
    for(int i=1;i<=n;i++){
        scanf("%d%lld",&w[i],&v[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&l[i],&r[i]);
    }
    while(left<=right){
        mid=(left+right)/2;
        check();
        if(y>s)left=mid+1;
        else right=mid-1;
    }
    printf("%lld",mi);
    return 0;
}