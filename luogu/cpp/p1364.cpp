#include<cstdio>
#include<algorithm>
using namespace std;
int f[103][103],n,p[102],t1,t2;
long long mi=9999999999,tot;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=99999999;
        }
    }
    for(int i=1;i<=n;i++){
       
        scanf("%d%d%d",&p[i],&t1,&t2);
        f[t1][i]=f[i][t1]=f[t2][i]=f[i][t2]=1;
        
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
               
                f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        tot=0;
        for(int j=1;j<=n;j++){
            if(i!=j)tot+=f[i][j]*p[j];
        }
        mi=min(mi,tot);
    }
    printf("%lld",mi);
    return 0;
}