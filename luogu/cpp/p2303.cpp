#include<cstdio>
#include<cmath>
#define ll long long
ll euler(ll x){
    ll ans=x,t=sqrt(x);
    for(int i=2;i<=t;i++){
        if(x%i==0){
            ans=ans-ans/i;
            while(x%i==0)x/=i;
        }
    }
    if(x>1)ans=ans-ans/x;
    return ans;
}
int main(){
    ll n;
    scanf("%lld",&n);
    ll ans=0,t=sqrt(n);
    for(int i=1;i<=t;i++){
        if(n%i==0){
            ans+=i*euler(n/i)+n/i*euler(i);
        }
    }
    if(t*t==n)ans-=t*euler(t);
    printf("%lld",ans);
    return 0;
}