#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const int NMAX = 2e5 + 2;
struct NODE {
    int u, v, val;
} t[NMAX << 2];
int a[NMAX];
int tot = 0;
inline int ls(int x) {return x << 1;}
inline int rs(int x) {return (x << 1) | 1;}
inline void pushup(int x) {t[x].val = max(t[ls(x)].val, t[rs(x)].val);}
void build(int root, int l, int r) {
    tot = max(tot, root);
    t[root].u = l, t[root].v = r;
    if (l == r) {
        t[root].val = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(ls(root), l, mid);
    build(rs(root), mid + 1, r);
    pushup(root);
}
int query(int l, int r, int p) {
    if (t[p].v <= r && l <= t[p].u)
        return t[p].val;
    if (t[p].u > r || t[p].v < l)
        return 0;
    return max(query(l, r, ls(p)), query(l, r, rs(p)));
}
void change(int u,int k,int b){
    if(k==t[u].u&&k==t[u].v){
        t[u].val=max(t[u].val,b);
        return;
    }
    change(u*2+(k>t[u*2].v),k,b);
    pushup(u);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,1,n);
    char c;int a,b;
    for(int i=1;i<=m;i++){
        cin>>c;scanf("%d%d",&a,&b);
        if(c=='Q')printf("%d\n",query(a,b,1));
        else change(1,a,b);
    }
    return 0;
}