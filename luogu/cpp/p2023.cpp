#include<cstdio>
#define ll long long
const int NMAX=1e5+10;
int n,pp,m;
ll a[NMAX<<2],tag[NMAX<<2],tagx[NMAX<<2],ans[NMAX<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return (x<<1)|1;}
inline void push_up(int x){ans[x]=(ans[ls(x)]+ans[rs(x)])%pp;}
void build(int root,int l,int r){
    tag[root]=0,tagx[root]=1;
    if(l==r){ans[root]=a[l];return;}
    int mid=l+(r-l)/2;
    build(ls(root),l,mid);
    build(rs(root),mid+1,r);
    push_up(root);
}
inline void spread(int root,int l,int r){
    if(!(tag[root]==0&&tagx[root]==1)){
        int mid=l+(r-l)/2;
        ans[ls(root)]=(ans[ls(root)]*tagx[root]+(mid-l+1)*tag[root])%pp;
        ans[rs(root)]=(ans[rs(root)]*tagx[root]+(r-mid)*tag[root])%pp;

        tagx[ls(root)]*=tagx[root];
        tagx[rs(root)]*=tagx[root];
        tag[ls(root)]=(tag[ls(root)]*tagx[root]+tag[root])%pp;
        tag[rs(root)]=(tag[rs(root)]*tagx[root]+tag[root])%pp;
        tagx[ls(root)]%=pp;
        tagx[rs(root)]%=pp;
        tag[root]=0;
        tagx[root]=1;
    }
}
void change(int nl,int nr,int l,int r,int root,int k){
    if(l>=nl&&r<=nr){
        ans[root]=(ans[root]+k*(r-l+1))%pp;
        tag[root]=(k+tag[root])%pp;
        return;
    }
    spread(root,l,r);
    int mid=l+(r-l)/2;
    if(nl<=mid)change(nl,nr,l,mid,ls(root),k);
    if(mid<nr)change(nl,nr,mid+1,r,rs(root),k);
    push_up(root);
}
void changex(int nl,int nr,int l,int r,int root,int k){
    if(l>=nl&&r<=nr){
        ans[root]=(ans[root]*k%pp);
        tagx[root]=tagx[root]*k%pp;
        tag[root]=tag[root]*k%pp;
        return;
    }
    spread(root,l,r);
    int mid=l+(r-l)/2;
    if(nl<=mid)changex(nl,nr,l,mid,ls(root),k);
    if(mid<nr)changex(nl,nr,mid+1,r,rs(root),k);
    push_up(root);
}
ll quest(int ql,int qr,int l,int r,int root){
    ll res=0;
    if(ql<=l&&qr>=r)return ans[root];
    int mid=l+(r-l)/2;
    spread(root,l,r);
    if(ql<=mid)res+=quest(ql,qr,l,mid,ls(root));
    if(qr>mid)res+=quest(ql,qr,mid+1,r,rs(root));
    return res%pp;
}
int main(){
    scanf("%d%d",&n,&pp);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    scanf("%d",&m);
    int op,t,g,c;
    for(int i=1;i<=m;i++){
        scanf("%d",&op);
        switch(op){
            case 1:
                scanf("%d%d%d",&t,&g,&c);
                changex(t,g,1,n,1,c);
                break;
            case 2:
                scanf("%d%d%d",&t,&g,&c);
                change(t,g,1,n,1,c);
                break;
            case 3:
                scanf("%d%d",&t,&g);
                printf("%lld\n",quest(t,g,1,n,1));
                break;
        }
    }
    return 0;
}
