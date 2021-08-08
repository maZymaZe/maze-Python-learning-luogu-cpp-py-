#include <algorithm>
#include <cstdio>
using namespace std;
int n, ma = -1, mi = 0x3f3f3f3f, x;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        ma = max(ma, x);
        mi = min(mi, x);
    }
    printf("%d\n", ma - mi - n + 1);
    return 0;
}