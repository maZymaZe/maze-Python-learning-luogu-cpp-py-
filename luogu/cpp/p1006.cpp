#include<cstdio>
int max(int a,int b,int c,int d){
    if(b>a)a=b;
    if(c>a)a=c;
    if(d>a)a=d;
    return a;
}
int f[110][55][55],mp[55][55],n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    for(int i=1;i<=n+m-1;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++)
            if(j<=i&&i>=k){
                f[i][j][k]=max(f[i-1][j][k],f[i-1][j][k-1],
                f[i-1][j-1][k],f[i-1][j-1][k-1])+mp[j][i-j+1]+mp[k][i-k+1];
                if(k==j)f[i][j][k]-=mp[j][i-j+1];
            }   
        }
    }
    printf("%d",f[n+m-1][n][n]);
    return 0;
}