#include<cstdio>
#define MAX 200005
int f[MAX],n,a[MAX],ans[MAX],h[MAX],m,vs[MAX];
int ff(int x){
    if(f[x]==x)return x;
    return f[x]=ff(f[x]);
}
struct edge{
    int u,v,nx;
}e[MAX<<1];
int main(){
    scanf("%d%d",&n,&m);
    int t1,t2;
    for(int i=0;i<m;i++){
        scanf("%d%d",&t1,&t2);
        e[(i<<1)+2].u=t1;
        e[(i<<1)+2].v=t2;
        e[(i<<1)+2].nx=h[t1];
        h[t1]=(i<<1)+2;
        e[(i<<1)|1].u=t2;
        e[(i<<1)|1].v=t1;
        e[(i<<1)|1].nx=h[t2];
        h[t2]=((i<<1)|1);
    }
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        f[i+1]=i+1;
    }
    int block=0;
    for(int i=n-1;i>=0;i--){
        block++;vs[a[i]]++;
        for(int j=h[a[i]];j;j=e[j].nx){
            if(vs[e[j].v]&&ff(a[i])!=ff(e[j].v)){
                f[ff(a[i])]=ff(e[j].v);
                block--;
            }
        }
        if(block==1)ans[i]=1;
    }
    for(int i=0;i<n;i++){
        if(ans[i])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
