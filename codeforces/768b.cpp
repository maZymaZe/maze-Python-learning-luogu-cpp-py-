#include <cstdio>
#include<unordered_map>
using namespace std;
unordered_map<long long,long long> mp;
long long a, l, r;
long long ql(long long x) {
    if(mp.count(x))return mp[x];
    long long tmp=(1 + 2 * ql(x / 2));
    mp.insert({x,tmp});
    return tmp;
}
long long f(long long a, long long l, long long r) {
    if (l > r)
        return 0;
    if (l == r && a == 1 && l == 1)
        return 1;
    long long ans = 0;
    long long len = ql(a / 2);
    if (l <= len + 1 && r >= len + 1)
        ans += (a % 2), ans += f(a / 2, l, len) + f(a / 2, 1, r - len - 1);
    else if (r <= len)
        ans = f(a / 2, l, r);
    else if (l > len + 1)
        ans = f(a / 2, l - len - 1, r - len - 1);
    return ans;
}
int main() {
    mp.insert({0,1});
    mp.insert({1,1});
    scanf("%lld%lld%lld", &a, &l, &r);
    if(a==0){
        printf("0");
        return 0;
    }
    printf("%lld", f(a, l, r));
    return 0;
}