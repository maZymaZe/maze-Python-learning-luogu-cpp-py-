#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int w, y, tots;
struct room {
    int s, a;
} b[100008];
int paia(const room& a, const room& b) {
    if (2 * a.s + a.a > b.s * 2 + b.a)
        return 1;
    else
        return 0;
}
int paib(const room& a, const room& b) {
    if (a.a > b.a)
        return 1;
    else
        return 0;
}

int main() {
    int n, c1, s0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i].s);
    }
    for (int j = 1; j <= n; j++) {
        scanf("%d", &b[j].a);
    }
    sort(b + 1, b + n + 1, paia);
    c1 = b[1].s * 2 + b[1].a;

    printf("%d\n", c1);
    tots = b[1].s;
    s0 = b[1].s;

    sort(b + 2, b + n + 1, paib);
    for (int l = 2; l <= n; l++) {
        tots = max(tots, b[l].s);
        c1 += b[l].a + 2 * (tots - s0);
        s0 = tots;
        printf("%d\n", c1);
    }

    return 0;
}