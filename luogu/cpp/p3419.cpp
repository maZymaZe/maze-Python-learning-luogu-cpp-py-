#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int NMAX = 5e5 + 10;
struct pr {
    int id, nx;
};
struct cmp {
    bool operator()(const pr& a, const pr& b) {
        return a.nx < b.nx || (a.nx == b.nx && a.id < b.id);
    }
};
int a[NMAX] = {0}, n, f, k, usng[NMAX] = {0}, las[NMAX], nex[NMAX], ans = 0;
priority_queue<pr, vector<pr>, cmp> q;
int main() {
    scanf("%*d%d%d", &k, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    memset(las, 0x3f, sizeof(las));
    for (int i = n; i >= 1; i--) {
        nex[i] = las[a[i]];
        las[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        f = 1;
        if (usng[a[i]]) {
            k++;
            q.push({a[i], nex[i]});
            continue;
        }
        if (q.size() >= k) {
            usng[q.top().id] = 0, q.pop();
        }
        q.push({a[i], nex[i]});
        usng[a[i]] = 1;
        ans++;
    }
    printf("%d", ans);
    return 0;
}
