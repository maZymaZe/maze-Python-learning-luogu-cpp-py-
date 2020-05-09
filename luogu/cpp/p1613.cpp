#include<cstdio>
#include<algorithm>
using namespace std;
int f[60][60][70],d[65][65],n,m,t1,t2,cnt=0;
int main(){
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)d[i][j]=9999999;
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&t1,&t2),f[t1][t2][0]=1;d[t1][t2]=1;
    }
    for(int o=1;o<=64;o++)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(f[j][i][o-1]&&f[i][k][o-1])
                f[j][k][o]=1,d[j][k]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
    printf("%d\n",d[1][n]);
    return 0;
}