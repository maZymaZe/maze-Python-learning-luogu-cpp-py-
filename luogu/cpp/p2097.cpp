#include<cstdio>
const int NMAX = 1e5 + 10;
int n,m,f[NMAX],ans,t1,t2,exist[NMAX];
int ff(int x) {
    if(f[x] == x)return x;
    return f[x]=ff(f[x]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&t1, &t2);
        f[ff(t1)]=ff(t2);
    }
    for(int i=1;i<=n;i++){
        if(!exist[ff(i)])ans++,exist[ff(i)]++;
    }
    printf("%d\n",ans);
    return 0;
}