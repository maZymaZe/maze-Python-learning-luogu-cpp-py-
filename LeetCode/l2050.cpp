class Solution {
   public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> inDegree(n), fs(n);
        vector<vector<int>> nx(n);
        for (const auto& v : relations) {
            inDegree[v[0] - 1]++;
            nx[v[1] - 1].push_back(v[0] - 1);
        }
        queue<int> q;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!inDegree[i]) {
                q.push(i);
                fs[i] = time[i];
                ans = max(ans, time[i]);
            }
        }

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int i : nx[t]) {
                fs[i] = max(fs[i], fs[t] + time[i]);
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    q.push(i);
                    ans = max(ans, fs[i]);
                }
            }
        }
        return ans;
    }
};