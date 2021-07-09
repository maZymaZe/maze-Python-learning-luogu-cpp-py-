bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}
class Solution {
   public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), cmp);
        vector<vector<int>> dp(n, vector<int>(k + 1, -0x3f3f3f3f));
        dp[0][0] = 0;
        dp[0][1] = events[0][2];
        for (int i = 1; i < n; i++) {
            int l = 0, r = i;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (events[mid][1] >= events[i][0]) {
                    r = mid;
                } else
                    l = mid;
            }
            if (events[l][1] < events[i][0]) {
                for (int j = 1; j <= k; j++) {
                    dp[i][j] = max(dp[i][j], dp[l][j - 1] + events[i][2]);
                }
            } else {
                dp[i][1] = max(dp[i][1], events[i][2]);
            }
            for (int j = 0; j <= k; j++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
        int ret = 0;
        for (int i = 0; i <= k; i++) {
            ret = max(ret, dp[n - 1][i]);
        }
        return ret;
    }
};