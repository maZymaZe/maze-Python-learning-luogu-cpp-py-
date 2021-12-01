#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> a, sc, npos[10];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        a.clear();
        sc.clear();
        for (int i = 0; i < 10; i++)
            npos[i].clear();
        int np[10], nps[10], k, n;
        scanf("%d%d", &k, &n);
        a.resize(n);
        sc.resize(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        memset(np, 0, sizeof(np));
        memset(nps, 0, sizeof(nps));
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = 0; j < a[i]; j++) {
                c += npos[j].size();
            }
            sc[i] = c;
            npos[a[i]].push_back(i);
        }
        if (n == 1) {
            printf("%d\n", a[0]);
            continue;
        }
        bool fs = true;
        int ls2[2];
        for (int i = 0; i < n; i++) {
            for (int j = 9; j >= 0; j--) {
                if (np[j] < npos[j].size()) {
                    int nxid = npos[j][np[j]];
                    int val = sc[nxid] - nps[j];
                    if (val <= k) {
                        k -= val;
                        if (i < n - 2) {
                            if (fs)
                                fs = false;
                            else
                                printf(" ");
                            printf("%d", j);
                        } else {
                            ls2[i + 2 - n] = j;
                        }
                        np[j]++;
                        for (int j2 = j + 1; j2 < 10; j2++) {
                            nps[j2]++;
                        }
                        break;
                    }
                }
            }
        }
        if (k) {
            for (int j = 0; j < 10; j++) {
                if (npos[j].size() > 1) {
                    k = 0;
                    break;
                }
            }
            if (k % 2)
                swap(ls2[0], ls2[1]);
        }
        for (int i = 0; i < 2; i++) {
            if (fs)
                fs = false;
            else
                printf(" ");
            printf("%d", ls2[i]);
        }
        printf("\n");
    }
    return 0;
}