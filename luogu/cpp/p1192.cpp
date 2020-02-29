#include<cstdio>
int u[103]={0},n,m,w;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        w=(i-1)%(m+1)+1;
        u[w]=0;
        for(int j=1;j<=m+1;j++)
        {
            if(j!=w)u[w]+=u[j];    
        }
        u[w]%=100003;
        if(i<=m)u[i]++;
        if(i==n)printf("%d",u[w]);
    }
    return 0;
}