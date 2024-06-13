class Solution {
   public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] > b[0];
             });

        int l = items.size(), sz = 0;
        long long tot = 0, ans = 0, nt = 0;
        vector<int> mt, vis(l + 1);
        for (int i = 0; i < l; i++) {
            if (sz < k) {
                sz++;
                if (vis[items[i][1]]) {
                    mt.push_back(items[i][0]);
                } else
                    vis[items[i][1]] = 1, nt++;
                tot += items[i][0];
                if (sz == k) {
                    ans = tot + nt * nt;
                }
            } else if (!vis[items[i][1]]) {
                if (!mt.empty()) {
                    tot -= mt.back();
                    tot += items[i][0];
                    mt.pop_back();
                    vis[items[i][1]] = 1;
                    nt++;
                    ans = max(ans, tot + nt * nt);
                }
            }
        }
        return ans;
    }
};