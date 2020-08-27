#include <cstdio>
typedef long long ll;
const int NMAX=3e6+10;
ll inv[NMAX]={0,1};
int n,p;
int main(){
    scanf("%d%d",&n,&p);
    printf("1\n");
    for(int i=2;i<=n;i++){
        inv[i]=(ll)p-(p/i)*inv[p%i]%p;
        printf("%lld\n",inv[i]);
    }
    return 0;
}
