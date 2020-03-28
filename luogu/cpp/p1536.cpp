#include<cstdio>
#include<cstring>
int n,m,ans,f[1020],t1,t2;
int ff(int x){
    if(f[x]==x)return x;
    return f[x]=ff(f[x]);
}
int main(){
    scanf("%d",&n);
    while(n!=0){
        scanf("%d",&m);
        ans=0;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d",&t1,&t2);
            f[ff(t1)]=ff(t2);
        }
        for(int i=2;i<=n;i++){
            if(ff(1)!=ff(i)){
                ans++;
                f[ff(i)]=ff(1);
            }
        }
        printf("%d\n",ans);
        scanf("%d",&n);
    }
    return 0;
}