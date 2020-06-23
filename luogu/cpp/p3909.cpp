#include<cstdio>
#define ll long long
#define MOD 1000000007
ll n,a[1000006],s[1000006],tot;
int main(){
    scanf("%lld", &n);
    for(int i=1;i<=n;i++){
        scanf("%lld", &a[i]);
        s[i]=(s[i-1]+a[i])%MOD;
    }
    for(int i=2;i<n;i++){
        tot=(tot+a[i]*s[i-1]%MOD*(s[n]-s[i])%MOD)%MOD;
    }
    tot=(tot*6)%MOD;
    tot=(tot+MOD)%MOD;
    printf("%lld",tot);
    return 0;
}