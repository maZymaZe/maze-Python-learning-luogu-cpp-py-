#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
char s[12];
int dp[1 << 10];
int hrz[1 << 10];
int vtc[1 << 10];
int getcs() {
    int ret = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++)
        ret = ret << 1 | (s[i] == '#');
    return ret;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    if (m == 1)
        return 0;
    int cmax = (1 << m);
    for (int i = 1; i < cmax; i++) {
        int lowbit = i & -i;
        hrz[i] = hrz[i ^ lowbit] + !((lowbit << 1) & i);
        vtc[i] = vtc[i ^ lowbit] + 1;
    }

    int ps = 0;
    for (int i = 0; i < n; i++) {
        int cs = getcs();
        for (int mask = (ps & cs), ci = mask;; ci = ((ci - 1) & mask)) {
            int cj = (ci ^ mask), cans = dp[cj];
            for (int ck = cj, lowbit = ck & -ck; ck;
                 ck -= lowbit, lowbit = (ck & -ck)) {
                int tmp = dp[cj ^ lowbit] + 1;
                if (tmp < cans)
                    cans = tmp;
            }
            dp[cj] = cans;
            if (ci == 0)
                break;
        }
        for (int ci = cs;; ci = ((ci - 1) & cs)) {
            int pre = ps & ci, cans = dp[pre] + vtc[pre ^ ci] + hrz[ci ^ cs];
            for (int cj = (cs ^ ci), lowbit = cj & -cj; cj;
                 cj -= lowbit, lowbit = (cj & -cj)) {
                int tmp = dp[ci | lowbit];
                if (tmp < cans)
                    cans = tmp;
            }
            dp[ci] = cans;
            if (ci == 0)
                break;
        }
        ps = cs;
    }
    printf("%d\n", dp[0]);
    return 0;
}
