#include<cstdio>
#define MAX 100004
#define ll long long
ll n,m,a[MAX],ans[MAX<<2],tag[MAX<<2],pp,tagx[MAX<<2];
inline ll ls(ll x){return x<<1;}
inline ll rs(ll x){return x<<1|1;}
void input(){
    scanf("%lld%lld%lld",&n,&m,&pp);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
}
inline void push_up(ll p){ans[p]=(ans[ls(p)]+ans[rs(p)])%pp;}
void build(ll root,ll l,ll r){
    tag[root]=0;tagx[root]=1;
    if(l==r){ans[root]=a[l];return;}
    ll mid=(l+r)>>1;
    build(ls(root),l,mid);
    build(rs(root),mid+1,r);
    push_up(root);
}
inline void spread(ll p,ll l,ll r){
    if(tag[p]!=0||tagx[p]!=1){
        ll mid=(l+r)>>1;
        ans[ls(p)]=(ans[ls(p)]*tagx[p]+(mid-l+1)*tag[p])%pp;
        ans[rs(p)]=(ans[rs(p)]*tagx[p]+(r-mid)*tag[p])%pp;
        
        tagx[ls(p)]*=tagx[p];
        tagx[rs(p)]*=tagx[p];
        tag[ls(p)]=(tag[p]+tag[ls(p)]*tagx[p])%pp;
        tag[rs(p)]=(tag[p]+tag[rs(p)]*tagx[p])%pp;
        tagx[ls(p)]%=pp;
        tagx[rs(p)]%=pp;
        tag[p]=0;
        tagx[p]=1;
    }
}
void change(ll nl,ll nr,ll l,ll r,ll p,ll k){
    if(l>=nl&&r<=nr){
        ans[p]+=k*(r-l+1);
        ans[p]%=pp;
        tag[p]+=k;
        tag[p]%=pp;
        return;
    }
    spread(p,l,r);
    ll mid=(l+r)>>1;
    if(nl<=mid)change(nl,nr,l,mid,ls(p),k);
    if(nr>mid)change(nl,nr,mid+1,r,rs(p),k);
    push_up(p);
}

ll quest(ll qx,ll qy,ll l,ll r,ll p){
    ll res =0;
    if(qx<=l&&qy>=r)return ans[p];
    ll mid =(l+r)>>1;;
    spread(p,l,r);
    if(qx<=mid)res+=quest(qx,qy,l,mid,ls(p));
    if(qy>mid)res+=quest(qx,qy,mid+1,r,rs(p));
    return res%pp;
}
void changex(ll nl,ll nr,ll l,ll r,ll p,ll k){ 
    if(l>=nl&&r<=nr){
        ans[p]=ans[p]*k%pp;
        tagx[p]=tagx[p]*k%pp;
        tag[p]=tag[p]*k%pp;
        return;
    }
    spread(p,l,r);
    ll mid=(l+r)>>1;
    if(nl<=mid)changex(nl,nr,l,mid,ls(p),k);
    if(nr>mid)changex(nl,nr,mid+1,r,rs(p),k);
    push_up(p);
}
int main(){
    ll t,b,c,d,e,f;
    input();
    build(1,1,n);
    while(m--){
        scanf("%lld",&t);
        if(t==1){
            scanf("%lld%lld%lld",&b,&c,&d);
            changex(b,c,1,n,1,d);
        }
        if(t==2){
            scanf("%lld%lld%lld",&b,&c,&d);
            change(b,c,1,n,1,d);
        }
        if(t==3){
            scanf("%lld%lld",&e,&f);
            printf("%lld\n",quest(e,f,1,n,1)%pp);
        }
    }
    return 0;
}