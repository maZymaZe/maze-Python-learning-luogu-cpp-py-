#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> e;
    int n, flag = 0;
    vector<int> ring;
    vector<int> vis;
    vector<int> road;
    void dfs(int p, int f) {
        if (!vis[p]) {
            vis[p] = 1;
            road.push_back(p);
            for (auto i : e[p]) {
                if (i == f)
                    continue;

                dfs(i, p);
            }
            road.pop_back();

        } else {
            if (flag)
                return;
            flag = 1;
            int len = road.size();
            for (int i = len - 1; i >= 0; i--) {
                ring.push_back(road[i]);
                if (p == road[i])
                    break;
            }
        }
    }
    void bfs(int s, vector<int>& dis) {
        dis.resize(n + 1), vis.resize(n + 1);
        for (int i = 0; i <= n; i++)
            dis[i] = n, vis[i] = 0;
        dis[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (vis[x])
                continue;
            vis[x] = 1;
            for (auto i : e[x]) {
                if (!vis[i]) {
                    dis[i] = dis[x] + 1;
                    q.push(i);
                }
            }
        }
    }
    int chaseGame(vector<vector<int>>& edges, int startA, int startB) {
        n = edges.size();
        e.resize(n + 1);
        vis.resize(n + 1);
        for (const auto& x : edges) {
            e[x[0]].push_back(x[1]);
            e[x[1]].push_back(x[0]);
        }

        dfs(1, -1);
        vector<int> d1, d2;
        bfs(startA, d1), bfs(startB, d2);
        if (d1[startB] == 1)
            return 1;
        if (ring.size() > 3) {
            for (auto i : ring) {
                if (d1[i] - d2[i] > 1)
                    return -1;
            }
        }

        queue<int> pos, time, player;
        vector<int> vvis(n + 1);
        vvis[startA] = 1, vvis[startB] = 2;
        int cb = 1;
        pos.push(startA);
        pos.push(startB);
        time.push(0), time.push(0);
        player.push(1), player.push(2);
        while (!pos.empty()) {
            int j = pos.front(), k = time.front(), l = player.front();
            pos.pop(), time.pop(), player.pop();
            if (l == 1) {
                for (auto i : e[j]) {
                    if (vvis[i] == 1)
                        continue;
                    if (vvis[i] == 2) {
                        cb--;
                        if (cb == 0)
                            return k + 1;
                    }
                    vvis[i] = 1;
                    pos.push(i), time.push(k + 1), player.push(1);
                }
            } else {
                for (auto i : e[j]) {
                    if (vvis[i] == 0) {
                        cb++;
                        vvis[i] = 2;
                        pos.push(i), time.push(k + 1), player.push(2);
                    }
                }
            }
        }
        return -2;
    }
};
int main() {
    vector<vector<int>> a = {{1, 2}, {2, 3}, {3, 1}, {3, 6}, {2, 4},
                             {4, 7}, {4, 5}, {5, 8}, {8, 9}};
    Solution().chaseGame(a, 9, 7);
}