#include<cstdio>
const int MAXN=5002;
int f[MAXN],n,m,p,t1,t2;
int ff(int x) {
    if(f[x] == x)return x;
    return f[x]=ff(f[x]);
}
int main(){
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&t1, &t2);
        f[ff(t1)]=ff(t2);
    }
    for(int i=1;i<=p;i++){
        scanf("%d%d",&t1, &t2);
        if(ff(t1)==ff(t2))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}