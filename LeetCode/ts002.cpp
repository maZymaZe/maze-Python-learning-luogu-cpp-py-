#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q, k;
    cin >> n >> m >> q >> k;
    unordered_set<int> visit;
    queue<int> que;
    vector<int> ans(n + 1, 1e9);
    int cnt = 0;
    for (int i = 0; i < q; ++i) {
        int s;
        cin >> s;
        que.push(s);
        visit.insert(s);
        ans[s] = cnt;
    }
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    while (que.size()) {
        cnt++;
        for (int dis = 0; dis < cnt * k; ++dis) {
            for (int i = que.size(); i; --i) {
                int x = que.front();
                que.pop();
                for (int ev : g[x]) {
                    if (!visit.count(ev)) {
                        que.push(ev);
                        visit.insert(ev);
                        ans[ev] = cnt;
                    }
                }
            }
        }
    }
    for (int i = 1; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
