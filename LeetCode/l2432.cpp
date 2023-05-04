class Solution {
   public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int l = logs.size();
        int ans = logs[0][0], ma = logs[0][1];
        for (int i = 1; i < l; i++) {
            int x = logs[i][1] - logs[i - 1][1];
            if (x > ma) {
                ma = x, ans = logs[i][0];
            } else if (x == ma && logs[i][0] < ans) {
                ans = logs[i][0];
            }
        }
        return ans;
    }
};