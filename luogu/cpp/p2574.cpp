#include<cstdio>
#define MAX 200004
#define ll long long
ll n,m,a[MAX],ans[MAX<<2],tag[MAX<<2];
inline ll ls(ll x){return x<<1;}
inline ll rs(ll x){return x<<1|1;}
void input(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%1lld",&a[i]);
}
inline void push_up(ll p){ans[p]=ans[ls(p)]+ans[rs(p)];}
void build(ll root,ll l,ll r){
    tag[root]=0;
    if(l==r){ans[root]=a[l];return;}
    ll mid=(l+r)>>1;
    build(ls(root),l,mid);
    build(rs(root),mid+1,r);
    push_up(root);
}
inline void spread(ll p,ll l,ll r){
    if(tag[p]!=0){
        ll mid=(l+r)>>1;
        
        ans[ls(p)]=(mid-l+1)-ans[ls(p)];
        ans[rs(p)]=(r-mid)-ans[rs(p)];

        tag[ls(p)]^=1;
        tag[rs(p)]^=1;
        tag[p]=0;
    }
}
void change(ll nl,ll nr,ll l,ll r,ll p){
    if(l>=nl&&r<=nr){
        ans[p]=(r-l+1-ans[p]);
        tag[p]^=1;
        return;
    }
    spread(p,l,r);
    ll mid=(l+r)>>1;
    if(nl<=mid)change(nl,nr,l,mid,ls(p));
    if(nr>mid)change(nl,nr,mid+1,r,rs(p));
    push_up(p);
}
ll quest(ll qx,ll qy,ll l,ll r,ll p){
    ll res =0;
    if(qx<=l&&qy>=r)return ans[p];
    ll mid =(l+r)>>1;;
    spread(p,l,r);
    if(qx<=mid)res+=quest(qx,qy,l,mid,ls(p));
    if(qy>mid)res+=quest(qx,qy,mid+1,r,rs(p));
    return res;
}
int main(){
    ll t,b,c,d,e,f;
    input();
    build(1,1,n);
    while(m--){
        scanf("%lld",&t);
        if(t==0){
            scanf("%lld%lld",&b,&c);
            change(b,c,1,n,1);
        }
        if(t==1){
            scanf("%lld%lld",&e,&f);
            printf("%lld\n",quest(e,f,1,n,1));
        }
    }
    return 0;
}