class Solution {
   public:
    vector<int> volunteerDeployment(vector<int>& finalCnt,
                                    long long totalNum,
                                    vector<vector<int>>& edges,
                                    vector<vector<int>>& plans) {
        vector<vector<int>> ps(finalCnt.size() + 1);
        for (auto& d : edges) {
            ps[d[0]].push_back(d[1]);
            ps[d[1]].push_back(d[0]);
        }
        vector<pair<int, long long>> t(ps.size());
        t[0] = {1, 0};
        int l = finalCnt.size();
        for (int i = 0; i < l; i++) {
            t[i + 1] = {0, finalCnt[i]};
        }
        for (int i = plans.size() - 1; i >= 0; i--) {
            int n = plans[i][0], idx = plans[i][1];
            auto& [ca, cb] = t[idx];
            if (n == 1) {
                ca *= 2, cb *= 2;
            } else {
                int f = (n == 2) ? -1 : 1;
                for (auto j : ps[idx]) {
                    auto& [a, b] = t[j];
                    a += ca * f;
                    b += cb * f;
                }
            }
        }
        int sx = 0;
        for (auto& [a, b] : t) {
            sx += a;
            totalNum -= b;
        }
        int x = totalNum / sx;
        vector<int> ans(t.size());
        for (int i = 0; i < t.size(); i++) {
            auto [a, b] = t[i];
            ans[i] = a * x + b;
        }
        return ans;
    }
};