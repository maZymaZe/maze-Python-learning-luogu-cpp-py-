class Solution {
   public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (auto v : accounts) {
            int tot = 0;
            for (int m : v)
                tot += m;
            ans = max(ans, tot);
        }
        return ans;
    }
};