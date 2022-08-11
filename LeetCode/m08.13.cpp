class Solution {
   public:
    vector<vector<int>> fa, so;
    vector<int> indo, dp;
    int pileBox(vector<vector<int>>& box) {
        int l = box.size();
        fa.resize(l);
        so.resize(l);
        indo.resize(l);
        dp.resize(l);
        queue<int> q;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                if (box[i][0] > box[j][0] && box[i][1] > box[j][1] &&
                    box[i][2] > box[j][2]) {
                    fa[j].push_back(i);
                    indo[j]++;
                    so[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < l; i++)
            if (indo[i] == 0)
                q.push(i);
        int ans = 0;
        while (!q.empty()) {
            int mx = 0, fr = q.front();
            q.pop();
            for (auto& x : fa[fr])
                mx = max(mx, dp[x]);
            dp[fr] = mx + box[fr][2];
            ans = max(ans, dp[fr]);
            for (auto& x : so[fr]) {
                indo[x]--;
                if (indo[x] == 0)
                    q.push(x);
            }
        }
        return ans;
    }
};