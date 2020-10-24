#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 1e6 + 5;

inline bool IsDigit(char c) {
    return (c >= '0' && c <= '9');
}
inline int Read() {
    int sum = 0, f = 1;
    char c = 0;
    while (!IsDigit(c)) {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (IsDigit(c)) {
        sum = (sum << 3) + (sum << 1) + c - '0';
        c = getchar();
    }
    return sum * f;
}

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int a[MAXN], m, b[MAXN], n, t, ac[MAXN];
int ans[MAXN], used[MAXN], pu = 0, maxlen = 0, pos = 1;

int main() {
    n = Read(), m = Read();
    for (int i = 1; i <= n; i++) {
        t = Read();
        a[i] = t, b[i] = t;
    }
    sort(b + 1, b + 1 + n);
    int pre = b[1], c = 1;
    for (int i = 2; i <= n; i++) {
        if (b[i] == pre) {
            c++;
        } else {
            for (int j = b[i - 1]; j <= m; j += b[i - 1])
                ac[j] += c;
            c = 1;
            pre = b[i];
        }
    }
    for (int j = b[n]; j <= m; j += b[n])
        ac[j] += c;
    for (int i = 1; i <= m; i++) {
        if (ac[i] > maxlen)
            maxlen = ac[i], pos = i;
    }
    printf("%d %d\n", pos, maxlen);
    if (pos) {
        for (int i = 1; i <= n; i++) {
            if (gcd(a[i], pos) == a[i])
                printf("%d ", i);
        }
    }
    return 0;
}