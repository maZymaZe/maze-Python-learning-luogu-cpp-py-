class Solution {
   public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int l = requests.size();
        int cnt[22] = {0}, ans = 0;
        for (int i = ((1 << l) - 1); i >= 0; i--) {
            memset(cnt, 0, sizeof(cnt));
            int t = 0;
            for (int j = 0; j < l; j++) {
                if (i & (1 << j)) {
                    cnt[requests[j][0]]++;
                    cnt[requests[j][1]]--;
                    t++;
                }
            }
            for (int j = 0; j <= n; j++) {
                if (cnt[j] != 0) {
                    t = -1;
                    break;
                }
            }
            ans = max(t, ans);
        }
        return ans;
    }
};