#include<cstdio>
#include<cstring>
int abs(int  x){
    if(x>0)return x;
    else return -x;
}
int min(int a,int b){
    if(a<b)return a;
    else return b;
}
int l1[1005],l2[1005],c[22]={0},n,d,ans=2000;
int f[1001][10001];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l1[i],&l2[i]);
    }
    memset(f,0x7F,sizeof(f));
    f[0][5000]=0;
    for(int i=1;i<=n;i++){
        for(int j=-5000;j<=5000;j++)
        {
            d=l1[i]-l2[i];
            f[i][j+5000]=min(f[i-1][j+5000-d],f[i-1][j+5000+d]+1);
        }
    }
    for(int i=0;i<=5000;i++){
        ans=min(f[n][i+5000],f[n][5000-i]);
        if(ans<=1000){
            printf("%d",ans);
            break;
        }
    }
    return 0;
}