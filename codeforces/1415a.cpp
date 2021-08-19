#include <algorithm>
#include <cstdio>
using namespace std;
int T, n, m, r, c;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &n, &m, &r, &c);
        printf("%d\n", max(max(n - r + m - c, r - 1 + c - 1),
                           max(n - r + c - 1, m - c + r - 1)));
    }
    return 0;
}