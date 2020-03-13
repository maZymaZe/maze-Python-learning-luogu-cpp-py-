#include<cstdio>
#include<cstring>
short n,m,mp[2501][2501],u[2501][2501],dp2[2501][2501],w;
short l[2501][2501],dp1[2501][2501],r[2501][2501],mx;
short mm(short a,short b,short c){
    if(b<a)a=b;
    if(c<a)a=c;
    return a;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        mx=0;
        scanf("%d",&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&mp[i][j]);
                if(i==1||j==1)dp1[i][j]=mp[i][j];
                if(i==1||j==m)dp2[i][j]=mp[i][j];
                if(mp[i][j])mx=1;
            }
        }
        for(int i=1;i<=n;i++){
            w=0;
            for(int j=1;j<=m;j++){
                if(mp[i][j]==1)l[i][j]=0,w=0;
                else w++,l[i][j]=w;
            }
        }
        for(int i=1;i<=n;i++){
            w=0;
            for(int j=m;j>=1;j--){
                if(mp[i][j]==1)r[i][j]=0,w=0;
                else w++,r[i][j]=w;
            }
        }
        for(int j=1;j<=m;j++){
            w=0;
            for(int i=1;i<=n;i++){
                if(mp[i][j]==1)u[i][j]=0,w=0;
                else w++,u[i][j]=w;
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                if(mp[i][j]){
                    dp1[i][j]=mm(dp1[i-1][j-1],u[i-1][j],l[i][j-1])+1;
                    if(dp1[i][j]>mx)mx=dp1[i][j];
                }
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=m-1;j>=1;j--){
                if(mp[i][j]){
                    dp2[i][j]=mm(dp2[i-1][j+1],u[i-1][j],r[i][j+1])+1;
                    if(dp2[i][j]>mx)mx=dp2[i][j];
                }
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
