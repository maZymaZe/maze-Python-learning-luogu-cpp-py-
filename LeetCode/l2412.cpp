class Solution {
   public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long tot = 0, ans = 0;
        int l = transactions.size();
        for (int i = 0; i < l; i++) {
            if (transactions[i][0] > transactions[i][1]) {
                tot += transactions[i][0];
                tot -= transactions[i][1];
            }
        }
        for (int i = 0; i < l; i++) {
            if (transactions[i][0] > transactions[i][1]) {
                ans = max(ans, tot + transactions[i][1]);
            } else {
                ans = max(ans, tot + transactions[i][0]);
            }
        }
        return ans;
    }
};