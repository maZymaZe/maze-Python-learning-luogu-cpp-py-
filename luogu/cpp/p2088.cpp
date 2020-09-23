#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct pr {
    int id, nx;
};
struct cmp {
    bool operator()(const pr& a, const pr& b) {
        return a.nx < b.nx || (a.nx == b.nx && a.id < b.id);
    }
};
int a[102] = {0}, n, k, usng[102] = {0}, las[102], nex[102], ans = 0;
priority_queue<pr, vector<pr>, cmp> q;
queue<int> qu[102];
int main() {
    scanf("%d%d", &k, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    memset(las, 0x3f, sizeof(las));
    for (int i = n; i >= 1; i--) {
        nex[i] = las[a[i]];
        las[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (usng[a[i]]) {
            q.push({a[i], nex[i]});
            continue;
        }
        if (q.size() >= k) {
            while (!q.empty() && !usng[q.top().id])
                q.pop();
            ans++;
            if (!q.empty())
                usng[q.top().id] = 0, q.pop();
            else
                ans--;
        }
        q.push({a[i], nex[i]});
        usng[a[i]] = 1;
    }
    printf("%d", ans);
    return 0;
}
