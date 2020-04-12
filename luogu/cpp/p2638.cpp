#include<cstdio>
unsigned long long yh[52][52],ans;
int n,a,b;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=51;i++){
        yh[i][1]=1;
        yh[i][i]=1;
    }
    for(int i=3;i<=51;i++){
        for(int j=2;j<i;j++){
            yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
        }
    }
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            ans+=yh[n+i][n]*yh[n+j][n];
        }
    }
   
    printf("%llu",ans);
    return 0;
}