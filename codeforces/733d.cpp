#include<cstdio>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
ll hs(ll a, ll b){return a*1000000000+b;}
struct pr{ll x;int idx;};
unordered_map<ll,pr> mp;
const int NMAX= 1e5+10;
ll x[NMAX],y[NMAX],z[NMAX],ans;
int n,f=0,s[2];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
        if(x[i]>y[i])swap(x[i],y[i]);
        if(y[i]>z[i])swap(y[i],z[i]);
        if(x[i]>y[i])swap(x[i],y[i]);
        if(x[i]>ans)ans = x[i],s[0]=i;
    }
    ll t;
    for(int i=1;i<=n;i++){
        t=hs(y[i],z[i]);
        if(mp.count(t)){
            ll tmp=min(y[i],min(z[i],x[i]+mp[t].x));
            if(tmp>ans){
                ans=tmp;
                s[0]=mp[t].idx,s[1]=i;
            }
        }
        if(mp.count(t)){
            if(x[i]>mp[t].x){
                mp[t]={x[i],i};
            }
        }else mp.insert({t,{x[i],i}});
        t=hs(x[i],y[i]);
        if(mp.count(t)){
            if(z[i]>mp[t].x){
                mp[t]={z[i],i};
            }
        }else mp.insert({t,{z[i],i}});
        t=hs(x[i],z[i]);
        if(mp.count(t)){
            if(y[i]>mp[t].x){
                mp[t]={y[i],i};
            }
        }else mp.insert({t,{y[i],i}});
    }
    if(s[1]){
        printf("2\n%d %d",s[0],s[1]);
    }else printf("1\n%d",s[0]);
    return 0;
}