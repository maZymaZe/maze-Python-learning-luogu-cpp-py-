#include<algorithm>
#include<cstdio>
#define MAX 1000004
using namespace std;

long long n,ave,ans,a[MAX],c[MAX],s;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        s+=a[i];
    }
    ave=s/n;
    for(int i=1;i<=n;i++){
        c[i] =c[i-1]+ a[i]-ave;
    }
    sort(c+1,c+1+n);
    for(int i= 1; i <= n; i++)ans+=abs(c[i]-c[n/2+1]);
    printf("%lld",ans);
    return 0;
}