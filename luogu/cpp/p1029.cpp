#include<cstdio>
long long gcd(long long a,long long b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
int main(){
    long long c=0,x,y;
    scanf("%lld%lld",&x,&y);
    for(long long i=x;i<=y;i+=x){
       if(x*y%i==0&&gcd(i,x*y/i)==x)
            c+=1;
    }
    printf("%lld",c);
    return 0;
}