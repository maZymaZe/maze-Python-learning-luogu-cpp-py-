class Solution {
   public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(),
             [&](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        int nr = ranges[0][1];
        int ans = 2, l = ranges.size(), MOD = 1e9 + 7;
        for (int i = 1; i < l; i++) {
            if (ranges[i][0] > nr) {
                ans = ans * 2 % MOD;
            }
            nr = max(nr, ranges[i][1]);
        }
        return ans;
    }
};