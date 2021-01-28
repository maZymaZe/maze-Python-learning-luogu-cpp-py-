#include<cstdio>
using namespace std;
int n,q;
int root[300005],cnt;
struct TREE{
    int l,r,sum;
}dat[300005<<5];
void insert(int &o,int l,int r,int pre,int x){
    int mid=(l+r)/2;
    o=++cnt;
    dat[o]=dat[pre];
    dat[o].sum++;
    if(l==r)return;
    if(x<=mid){
        insert(dat[o].l,l,mid,dat[pre].l,x);
    }else
    {
        insert(dat[o].r,mid+1,r,dat[pre].r,x);
    }
}
int query(int l,int r,int x,int y,int k){
    if(l==r)return l;
    int mid=(l+r)/2;
    if(dat[y].sum-dat[x].sum<=k)return -1;
    int res;
    if(dat[dat[y].l].sum-dat[dat[x].l].sum>k){
        res=query(l,mid,dat[x].l,dat[y].l,k);
        if(res>0)return res;
    }
    if(dat[dat[y].r].sum-dat[dat[x].r].sum>k){
        res=query(mid+1,r,dat[x].r,dat[y].r,k);
        if(res>0)return res;
    }
    return -1;
}
int main(){
    scanf("%d%d",&n,&q);
    int x,l,r,k;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        insert(root[i],1,n,root[i-1],x);
    }
    while(q--){
        scanf("%d%d%d",&l,&r,&k);
        k=(r-l+1)/k;
        printf("%d\n",query(1,n,root[l-1],root[r],k));
    }
    return 0;
}