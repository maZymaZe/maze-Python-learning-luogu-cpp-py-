#include<cstdio>
int a[40][40]={0},n,m;
int main(){
    a[0][1]=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j==1)a[i][1]=a[i-1][2]+a[i-1][n];
            else if(j==n)a[i][n]=a[i-1][n-1]+a[i-1][1];
            else a[i][j]=a[i-1][j+1]+a[i-1][j-1];
        }
    }
    printf("%d",a[m][1]);
    return 0;
}