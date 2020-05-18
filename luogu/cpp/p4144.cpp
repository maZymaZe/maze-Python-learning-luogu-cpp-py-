#include<cstdio>
long long n,t,m=-8989,b,p,ans=1;
long long ksm(long long q, long long w){
    if(w==0)return 1%p;
    long long sum=ksm(q,w>>1);
    sum=sum*sum%p;
    if(w&1)sum=sum*q%p;
    return sum;
}
int main(){
    scanf("%lld%lld%lld",&n,&b,&p);
    for(int i=1;i<=n;i++){
        scanf("%lld",&t);
        if(t>m)m=t;
    }
    m=(m*2+233)%p;
    printf("%lld",ksm(m,b));
    return 0;
}