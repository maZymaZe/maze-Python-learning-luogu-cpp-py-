#include<cstdio>
#define MAX 200004
#define ll long long
int n,m;
ll tag[MAX<<2],a[MAX],node[MAX<<2],s[MAX];
inline ll ls(ll x){return x<<1;}
inline ll rs(ll x){return (x<<1)|1;}
inline void pushup(ll x){node[x]=node[ls(x)]+node[rs(x)];}
void build(ll root,ll l,ll r){
    tag[root]=0;
    if(l==r){node[root]=a[l];return;}
    ll mid=(l+r)>>1;
    build(ls(root),l,mid);
    build(rs(root),mid+1,r);
    pushup(root);
}
inline void spread(ll root,ll l,ll r){
    ll mid=(l+r)>>1;
    if(tag[root]){
        node[ls(root)]+=tag[root]*(mid-l+1);
        node[rs(root)]+=tag[root]*(r-mid);
        tag[ls(root)]+=tag[root];
        tag[rs(root)]+=tag[root];
        tag[root]=0;
    }
}
void change(ll nl,ll nr,ll root,ll l,ll r,ll k){
    if(nl<=l&&nr>=r){
        node[root]+=(r-l+1)*k;
        tag[root]+=k;
        return;
    }
    spread(root,l,r);
    ll mid=(l+r)>>1;
    if(nl<=mid){
        change(nl,nr,ls(root),l,mid,k);
    }
    if(nr>mid){
        change(nl,nr,rs(root),mid+1,r,k);
    }
    pushup(root);
}
ll quest(ll nl,ll nr,ll root,ll l,ll r){
    ll ans=0;
    if(nl<=l&&nr>=r){
        spread(root,l,r);
        return node[root];
    }
    spread(root,l,r);
    ll mid=(l+r)>>1;
    if(nl<=mid){
        ans+=quest(nl,nr,ls(root),l,mid);
    }
    if(nr>mid){
       ans+=quest(nl,nr,rs(root),mid+1,r);
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    build(1,1,n);
    int t,a,b,c;
    for(int i=1;i<=m;i++){
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d%d",&a,&b,&c);
            change(a,b,1,1,n,c);
        }
        else if(t==2){
            scanf("%d",&a);
            change(1,1,1,1,n,a);
        }
        else if(t==3){
            scanf("%d",&a);
            change(1,1,1,1,n,-a);
        }
        else if(t==4){
            scanf("%d%d",&a,&b);
            printf("%lld\n",quest(a,b,1,1,n));
        }
        else if(t==5){
            printf("%lld\n",quest(1,1,1,1,n));
        }
    }
    return 0;
}