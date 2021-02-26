#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll la, ra, ta, lb, rb, tb;
int main() {
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    la++,ra++,lb++,rb++;
    ll stp = __gcd(ta, tb);
    ll ans = 0;
    ll del1 = la - lb;
    ll t1 = del1 / stp;

    ll tla = la - stp * t1, tra = ra - stp * t1;
    ans = max(ans, min(tra, rb) - max(tla, lb) + 1);

    
    t1++;

    tla = la - stp * t1, tra = ra - stp * t1;
    ans = max(ans, min(tra, rb) - max(tla, lb) + 1);

    t1-=2;

    tla = la - stp * t1, tra = ra - stp * t1;
    ans = max(ans, min(tra, rb) - max(tla, lb) + 1);

    ll del2 = ra - rb;
    ll t2 = del2 / stp;

    tla = la - stp * t2, tra = ra - stp * t2;
    ans = max(ans, min(tra, rb) - max(tla, lb) + 1);

    t2++;

    tla = la - stp * t2, tra = ra - stp * t2;
    ans = max(ans, min(tra, rb) - max(tla, lb) + 1);

    t2-=2;

    tla = la - stp * t2, tra = ra - stp * t2;
    ans = max(ans, min(tra, rb) - max(tla, lb) + 1);

    cout << ans << endl;
    return 0;
}