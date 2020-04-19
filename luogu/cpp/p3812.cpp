#include <cstdio>
#include <cstring>
#define ll long long
struct Lbase {
    ll d[61];
    Lbase() { memset(d, 0, sizeof(d)); }
    bool insert(ll x) {
        for (int i = 60; i >= 0; i--) {
            if (x & ((ll)1 << i)) {
                if (d[i])
                    x ^= d[i];
                else {
                    d[i] = x;
                    break;
                }
            }
        }
        return x > 0;
    }
    ll qmax(){
        ll x=0;
        for (int i=60;i>=0;i--){
            if(d[i]&&(x^d[i])>x)x^=d[i];
        }
        return x;
    }
    void merge(const Lbase&a){
        for(int i=60;i>=0;i--){
            if(a.d[i])insert(a.d[i]);
        }
    }
};
int main(){
    Lbase lb;
    int n;
    ll t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&t);
        lb.insert(t);
    }
    printf("%lld",lb.qmax());
    return 0;
}