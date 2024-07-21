class Solution {
   public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> e(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int dx = bombs[i][0] - bombs[j][0],
                    dy = bombs[i][1] - bombs[j][1], r = bombs[i][2];
                if ((long long)r * r >= (long long)dx * dx + (long long)dy * dy)
                    e[i].push_back(j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            vector<int> vis(n);
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                if (vis[t])
                    continue;
                vis[t] = 1;
                cnt++;
                for (int j : e[t]) {
                    if (!vis[j])
                        q.push(j);
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};