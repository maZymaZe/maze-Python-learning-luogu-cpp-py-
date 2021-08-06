class Solution {
   public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), ansmsk, ans = 0x3f3f3f3f;
        if (n == 1)
            return 0;
        ansmsk = (1 << n) - 1;
        vector<int> res((n + 1) << n, -1);
        for (int i = 0; i < n; i++) {
            int bg = ((i << n) | (1 << i));
            res[bg] = 0;
            queue<int> q;
            q.push(bg);
            while (!q.empty()) {
                int hd = q.front();
                q.pop();
                int s = hd >> n;
                for (auto j : graph[s]) {
                    int nx = (j << n) | (hd & ansmsk) | (1 << j);
                    if (res[nx] == -1) {
                        q.push(nx);
                        res[nx] = res[hd] + 1;
                        if ((nx & ansmsk) == ansmsk) {
                            ans = min(ans, res[nx]);
                        }
                    }
                }
            }
            fill(res.begin(), res.end(), -1);
        }
        return ans;
    }
};