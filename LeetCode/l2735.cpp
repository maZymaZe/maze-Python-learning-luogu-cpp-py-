class Solution {
   public:
    long long minCost(vector<int>& nums, int x) {
        long long tot = 0, ans = 0;
        int l = nums.size();
        vector<int> cur = nums;
        for (int i = 0; i < l; i++) {
            tot += cur[i];
        }
        ans = tot;
        for (int i = 1; i < l; i++) {
            tot += x;
            vector<int> tc = cur;
            for (int j = 0; j < l; j++) {
                int nc = min(cur[j], cur[(j + l - 1) % l]);
                tot -= cur[j] - nc;
                tc[j] = nc;
            }
            cur.swap(tc);
            ans = min(ans, tot);
        }
        return ans;
    }
};