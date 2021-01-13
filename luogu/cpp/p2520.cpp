#include<cstdio>
#include<algorithm>
using namespace std;
long long d,a,b,x,y;
int T;
inline bool ok(long long x, long long y){
    return x%d==0 && y%d==0;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&a, &b, &x, &y);
        d=(long long)__gcd(a,b)*2;
        if(ok(x,y)||ok(x+a,y+b)||ok(x+b,y+a)||ok(x+a+b,y+a+b))printf("Y\n");
        else printf("N\n");
    }
    return 0;
}