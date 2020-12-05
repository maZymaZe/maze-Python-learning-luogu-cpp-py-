#include<cstdio>
#include<cmath>
int main(){
    long long n;
    scanf("%lld", &n);
    long long l=1,r=2000000000;
    while(l<r){
        long long i=(l+r)/2;
        if(log10((long double)i)*i>=n-1){
           r=i;
        }else l=i+1;
    }
    printf("%lld",l);
    return 0;
}