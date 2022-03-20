class Solution {
   public:
    vector<vector<int>> nx;
    int n;
    vector<int> dis;

    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        n = patience.size();
        nx.resize(n);
        for (const auto& e : edges) {
            nx[e[0]].push_back(e[1]);
            nx[e[1]].push_back(e[0]);
        }
        dis = vector<int>(n, 0x3f3f3f3f);
        dis[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (int i : nx[p]) {
                if (dis[i] == 0x3f3f3f3f) {
                    dis[i] = dis[p] + 1;
                    q.push(i);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, ((2 * dis[i] - 1) / patience[i] * patience[i] +
                            2 * dis[i]));
        }
        return ans + 1;
    }
};