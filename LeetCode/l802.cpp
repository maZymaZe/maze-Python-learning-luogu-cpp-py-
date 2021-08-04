class Solution {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n + 1), od(n + 1);
        vector<vector<int>> v(n + 1, vector<int>());
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i])
                v[it].push_back(i), od[i]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (od[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            vis[t] = 1;
            for (auto i : v[t]) {
                od[i]--;
                if (od[i] == 0)
                    q.push(i);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (vis[i])
                ans.push_back(i);
        return ans;
    }
};