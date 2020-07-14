#include<cstdio>
int main(){
    int n=0;
    scanf("%d",&n);
    double f[10005]={0.0},g[10005]={0.0};
    for(int i=n-1;i>=0;i--){
        f[i]=f[i+1]+1.0*n/(n-i);
        g[i]=1.0*i/(n-i)*f[i]+g[i+1]+f[i+1]+1.0*n/(n-i);
    }
    printf("%.2lf",g[0]); 

    return 0;
}