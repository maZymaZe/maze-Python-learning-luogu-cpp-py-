#include<queue>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
ll l,n,m,d[50005],pre=0,ans;

int main(){
    scanf("%lld%lld%lld",&l,&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&d[i]);
    }
    ll left=0,right=l;
    while(left<=right){
        ll mid=(left+right)/2;
        ll nw=0,s=0;
        for(int i=1;i<=n;i++){
            if(d[i]-d[nw]<mid)s++;
            else nw=i;
        }
        if(s<=m){
            ans=mid;
            left=mid+1;
        }
        else right=mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}
