#include<cstdio>
const int NMAX=21,MMAX=5e5+10;
const int AMAX=1<<NMAX;
int n,m,all,a[MMAX],cnt[NMAX];
long long w[NMAX][NMAX],f[AMAX];
int main(){
    n=20;
    scanf("%d",&m);
    all=1<<n;
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
        a[i]--;
        cnt[a[i]]++;
        for(int j=0;j<n;j++){
            w[j][a[i]]+=cnt[j];
        }
    }
    for(int i=1,j;i<all;i++){
        f[i]=1e18;
        for(int u=0;u<n;u++){
            if((1<<u)&i){
                j=(1<<u)^i;
                long long sum=0;
                for(int v=0;v<n;v++){
                    if((1<<v)&j){
                        sum+=w[u][v];
                    }
                }
                if(f[i]>f[j]+sum)f[i]=f[j]+sum;
            }
        }
    }
    printf("%lld",f[all-1]);
    return 0;
}