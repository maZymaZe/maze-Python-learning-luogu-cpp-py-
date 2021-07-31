#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int NMAX = 1e6 + 10;
char s[NMAX];
int sa[NMAX], rk[NMAX << 1], n, ork[NMAX << 1];
int id[NMAX], px[NMAX], cnt[NMAX];
bool cmp(int x, int y, int w) {
    return ork[x] == ork[y] && ork[x + w] == ork[y + w];
}
int main() {
    int i, m = 300, p, w;
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (i = 1; i <= n; i++) {
        rk[i] = s[i];
        ++cnt[s[i]];
    }
    for (i = 1; i <= 300; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (i = n; i > 0; i--) {
        sa[cnt[s[i]]--] = i;
    }

    for (w = 1;; w <<= 1, m = p) {
        // id 2nd key
        for (p = 0, i = n; i > n - w; i--) {
            id[++p] = i;
            // empty 2nd key
        }
        for (i = 1; i <= n; i++) {
            if (sa[i] > w) {
                id[++p] = sa[i] - w;
            }
        }
        memset(cnt, 0, sizeof(cnt));
        for (i = 1; i <= n; i++) {
            px[i] = rk[id[i]];
            ++cnt[px[i]];
        }
        for (i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (i = n; i > 0; i--) {
            sa[cnt[px[i]]--] = id[i];
        }
        memcpy(ork, rk, sizeof(ork));
        for (p = 0, i = 1; i <= n; i++) {
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
        }
        if (p == n) {
            for (i = 1; i <= n; i++) {
                sa[rk[i]] = i;
            }
            break;
        }
    }
    for (i = 1; i <= n; i++) {
        printf("%d ", sa[i]);
    }
    return 0;
}