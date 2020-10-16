#include <cstdio>

const int NMAX = 3e5+20;

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

int n, q, cnt[NMAX], used[NMAX], tot = 0, op[NMAX], t[NMAX], d3 = 0, td3 = 0,
                                 d3cnt[NMAX];
int main() {
    n = Read(), q = Read();
    for (int i = 0; i < q; i++) {
        op[i] = Read(), t[i] = Read();
        if (op[i] == 1) {
            cnt[t[i]]++;
            tot++;
        } else if (op[i] == 2) {
            tot -= (cnt[t[i]] - used[t[i]]);
            used[t[i]] = cnt[t[i]];
        } else {
            if (t[i] > td3) {
                int mw = t[i] - td3, p = d3;
                for (int w = 1; w <= mw; w++) {
                    while (op[p] != 1)
                        p++;
                    d3cnt[t[p]]++;
                    if (d3cnt[t[p]] > used[t[p]]) {
                        used[t[p]] = d3cnt[t[p]];
                        tot--;
                    }
                    p++;
                }
                d3 = p, td3 = t[i];
            }
        }
        printf("%d\n", tot);
    }
    return 0;
}