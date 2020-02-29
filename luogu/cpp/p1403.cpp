#include<cmath>
#include<cstdio>
long long s=0;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        s+=(n/i);
    }
    printf("%lld",s);
    return 0;
}