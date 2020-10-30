#include<cstdio>
int f[105][105]={0},n,m,t1,t2,ans=0;
int main() {
    scanf("%d%d", &n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d", &t1, &t2);
        f[t1][t2]=1;
        f[t2][t1]=-1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(!f[i][j]){
                    if(f[i][k]==f[k][j])f[i][j]=f[i][k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        int t=1;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(!f[i][j]){
                t=0;break;
            }
        }
        ans+=t;
    }
    printf("%d",ans);
    return 0;
}