#include<cstdio>
int mp[110][110],f[110][110][110],n,m,ans=1,ff,t;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&mp[i][j]);
            f[i][j][1]=mp[i][j];
        }
    t=(m>n)?n:m;
    for(int s=2;s<=n;s++){
        ff=0;
        for(int i=1;i<=n-s+1;i++)
            for(int j=1;j<=m-s+1;j++){
                f[i][j][s]=mp[i][j]*mp[i+s-1][j+s-1]*f[i+1][j][s-1]*f[i][j+1][s-1];
                if(f[i][j][s])ff=1,ans=s;
            }
        if(ff==0)break;
    }
    printf("%d",ans);
    return 0;
}