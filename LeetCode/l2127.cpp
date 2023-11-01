class Solution {
   public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n);
        for (int i = 0; i < n; i++) {
            indegree[favorite[i]]++;
        }
        vector<int> used(n), f(n, 1);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            used[u] = 1;
            int v = favorite[u];
            f[v] = max(f[v], f[u] + 1);
            --indegree[v];
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
        int ring = 0, tot = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                int j = favorite[i];
                if (favorite[j] == i) {
                    tot += f[i] + f[j];
                    used[i] = used[j] = 1;
                } else {
                    int u = i, cnt = 0;
                    while (1) {
                        ++cnt;
                        u = favorite[u];
                        used[u] = 1;
                        if (u == i) {
                            break;
                        }
                    }
                    ring = max(ring, cnt);
                }
            }
        }
        return max(tot, ring);
    }
};