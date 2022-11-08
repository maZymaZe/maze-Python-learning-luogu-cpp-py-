#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int n, m, q, cnt = 0, t, t1, t2;
unordered_map<string, int> mp;
vector<int> con[1003], dis[1002];
int gs(string& s) {
    if (mp.count(s))
        return mp[s];
    cnt++;
    mp[s] = cnt;
    return cnt;
}
string s1, s2;
struct PR {
    int pos;
    long long dis;
    bool operator<(const PR& x) const { return dis > x.dis; }
};
long long dj(int s, int t) {
    priority_queue<PR> pq;
    pq.push({s, 0});
    long long dd[1002];
    for (int i = 0; i <= n; i++)
        dd[i] = 0x3f3f3f3f3f3f3f3fll;
    dd[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().pos;
        long long w = pq.top().dis;
        pq.pop();
        int l = con[u].size();
        for (int i = 0; i < l; i++) {
            if (dd[con[u][i]] > w + dis[u][i]) {
                dd[con[u][i]] = w + dis[u][i];
                pq.push({con[u][i], dd[con[u][i]]});
            }
        }
    }
    return dd[t];
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        cin >> s1 >> s2 >> t;
        t1 = gs(s1), t2 = gs(s2);
        con[t1].push_back(t2);
        dis[t1].push_back(t);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        cin >> s1 >> s2;
        t1 = gs(s1), t2 = gs(s2);
        long long ans = dj(t1, t2);
        if (ans == 0x3f3f3f3f3f3f3f3fll)
            printf("INF\n");
        else
            printf("%lld\n", ans);
    }
    return 0;
}