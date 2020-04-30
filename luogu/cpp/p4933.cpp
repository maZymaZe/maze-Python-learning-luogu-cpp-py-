#include<cstdio>
#define MOD 998244353
long long ans;
int a[1002]={0},n,f[1002][40300]={0},v[1002][40300]={0};
int main(){
    scanf("%d",&n);
    for(int i=1; i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1; i<=n;i++){
        for(int j=i-1;j>=1; j--){
            if(!v[j][a[j]-a[i]+20100]){
                f[j][a[j]-a[i]+20100]++;
                v[j][a[j]-a[i]+20100]++;
            }
            ans=(long long)(ans+f[j][a[j]-a[i]+20100])%MOD;
            f[i][a[j]-a[i]+20100]=(long long)(f[j][a[j]-a[i]+20100]+f[i][a[j]-a[i]+20100])%MOD;

        }
    }
    printf("%lld",(ans+n)%MOD);
    return 0;
}