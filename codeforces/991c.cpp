#include<cstdio>
#include<algorithm>
using namespace std;
long long l,r,s,mid;
bool ck(long long k,long long t){
    long long q=0;
    while(t){
        q+=min(k,t);
        t-=min(k,t);
        t-=t/10;
    }
    return q*2>=s;
}
int main(){
    scanf("%lld",&s);
    l=1,r=(s+1)/2;
    while(l<r){
        mid=(l+r)/2;
        if(ck(mid,s)){
            r=mid;
        }else l=mid+1;
    }
    printf("%lld",l);
    return 0;
}