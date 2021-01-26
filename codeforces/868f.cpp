#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long dp[100005][22],ans=0;
int buc[100005],L,R;
int n,m,a[100005];
void update(int c,int d){
    ans+=d*buc[c]*(long long)(buc[c]-1)/2;
}
long long cal(int l,int r){
    while(L<l)update(a[L],-1),buc[a[L]]--,update(a[L],1),L++;
    while(L>l)L--,update(a[L],-1),buc[a[L]]++,update(a[L],1);
    while(R<r)R++,update(a[R],-1),buc[a[R]]++,update(a[R],1);
    while(R>r)update(a[R],-1),buc[a[R]]--,update(a[R],1),R--;
    return ans;
}
void solve(int lb,int rb,int l,int r,int cur){
    if(lb>rb||l>r)return;
    int mid=(l+r)>>1,d=0;
    long long res=1e18;
    for(int i=lb;i<=rb;i++){
        long long tmp=cal(i+1,mid);
        if(res>dp[i][cur-1]+tmp)res=dp[i][cur-1]+tmp,d=i;
    }
    dp[mid][cur]=res;
    solve(lb,d,l,mid-1,cur),solve(d,rb,mid+1,r,cur);
}
int main(){
    memset(dp,0x3f, sizeof(dp));dp[0][0] =0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    buc[a[1]]++,L=1,R=1;
    for(int i=1;i<=m;i++)solve(0,n-1,1,n,i);
    printf("%lld\n",dp[n][m]);
    return 0;
}