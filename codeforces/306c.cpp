#include<cstdio>
typedef long long ll;
const ll MOD= 1e9 + 9;
const int NMAX=4020;
int fac[NMAX],inv[NMAX];
int n,w,b,ans;
void calfac(){
    fac[0]=1;
    for(int i=1;i<NMAX;i++)fac[i]=(ll)i*fac[i-1]%MOD;
}
void calinv(){
    inv[0]=inv[1]=1;
    for(int i=2;i<NMAX;i++){
        inv[i]=MOD-(ll)(MOD/i)*inv[MOD%i]% MOD;
    }
    for(int i=1;i<NMAX;i++)inv[i]=(ll)inv[i-1]*inv[i]%MOD;
}
int cnm(int n,int m){ return (ll)fac[n]*inv[m]%MOD*inv[n-m]%MOD;}
int main() {
    calfac();
    calinv();
    scanf("%d%d%d",&n,&w,&b);
    for(int i=1;i<=b;i++){
        if(n-i>=2&&n-i<=w)ans=((ll)ans+(ll)(n-i-1)*cnm(b-1,i-1)%MOD*cnm(w-1,n-i-1)%MOD)%MOD;
    }
    ans=(ll)ans*fac[w]%MOD*fac[b]%MOD;
    printf("%d",ans);
}