#include<cstdio>
#include<algorithm>
using namespace std;
int f[103][103],n,a[10003],m;
long long ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&f[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
            }
        }
    }
    //output
    for(int i=1;i<m;i++){
        ans+=f[a[i]][a[i+1]];
    }
    ans+=f[1][a[1]]+f[a[m]][n];
    printf("%lld",ans);
    return 0;
}