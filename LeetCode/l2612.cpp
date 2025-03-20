class Solution {
   public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        unordered_set<int> ban{banned.begin(), banned.end()};
        set<int> sets[2];
        for (int i = 0; i < n; ++i) {
            if (i != p && !ban.count(i)) {
                sets[i % 2].insert(i);
            }
        }
        vector<int> ans(n, -1);
        queue<int> q;
        q.push(p);
        ans[p] = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int mn = max(i - k + 1, k - i - 1);
            int mx = min(i + k - 1, n * 2 - k - i - 1);
            auto it = sets[mx % 2].lower_bound(mn);
            while (it != sets[mx % 2].end()) {
                if (*it > mx) {
                    break;
                }
                ans[*it] = ans[i] + 1;
                q.push(*it);
                it = sets[mn % 2].erase(it);
            }
        }
        return ans;
    }
};
