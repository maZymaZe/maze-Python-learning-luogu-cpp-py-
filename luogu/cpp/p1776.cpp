#include<cstdio>
const int NMAX=1e6+ 10;
int max(int a,int b){ return a > b ? a : b;}
int f[NMAX],w[NMAX],v[NMAX],n,m,ans,cnt=0,a,b,c;
int main(){
    scanf("%d%d", &n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d", &a, &b, &c);
        for(int j=1;j<=c;j<<=1){
            v[++cnt]=j*a,w[cnt]=j*b,c-=j;
        }
        if(c)v[++cnt]=c*a,w[cnt]=c*b;
    }
    for(int i=1;i<=cnt;++i){
        for(int j=m;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+v[i]);
        }
    }
    printf("%d\n",f[m]);
    return 0;
}