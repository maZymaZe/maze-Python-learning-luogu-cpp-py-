#include<cstdio>
#include<cstring>
#define INF 2e9
int n,m,u[3001],v[3001],w[3001],d[2002],t;
void bf(){
    scanf("%d%d",&n,&m);
    int f=0;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
    }
    for(int i=1;i<=m;i++){
        if(u[i]==1||(w[i]>=0)&&(v[i]==1)){
            f=1;break;
        }
    }
    if(f==0){
        printf("NO\n");
        return;
    }
    memset(d,0x3f,sizeof(d));
    d[1]=0;
    for(int i=1;i<=n;i++){
        f=1;
        for(int j=1;j<=m;j++){
            if(d[v[j]]>d[u[j]]+w[j]){
                d[v[j]]=d[u[j]]+w[j];
                f=0;
            }
            if(w[j]>=0){
                if(d[u[j]]>d[v[j]]+w[j]){
                    d[u[j]]=d[v[j]]+w[j];
                    f=0;
                }
            }
        }
        if(f==1&&i<=n-1){
            printf("NO\n");
            return;
        }
        if(f==1&&i==n){
            printf("YES\n");
            return;
        }
    }
    printf("YES\n");
    return;
}
int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        bf();
    }
    return 0;
}