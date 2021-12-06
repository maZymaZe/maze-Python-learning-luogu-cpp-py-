class Solution {
   public:
    vector<int> ps;
    static const int N = 1000002;
    int isp[N], fc[N];
    int dp[N];
    int splitArray(vector<int>& nums) {
        for (int i = 2; i < N - 2; i++) {
            fc[i] = 0x3f3f3f3f;
            if (isp[i] == 0) {
                ps.push_back(i);
                for (int j = i + i; j <= N - 2; j += i) {
                    if (isp[j] == 0)
                        isp[j] = i;
                }
            }
        }
        int pc = ps.size();
        dp[0] = 0;
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            dp[i + 1] = dp[i] + 1;
            int t = nums[i];
            for (int j = isp[t];; j = isp[t]) {
                if (j == 0) {
                    dp[i + 1] = min(dp[i + 1], fc[t] + 1);
                    break;
                } else {
                    dp[i + 1] = min(dp[i + 1], fc[j] + 1);
                    while (t % j == 0)
                        t /= j;
                }
                if (t == 1)
                    break;
            }
            t = nums[i];
            for (int j = isp[t];; j = isp[t]) {
                if (j == 0) {
                    fc[t] = min(fc[t], dp[i]);
                    break;
                } else {
                    fc[j] = min(fc[j], dp[i]);
                    while (t % j == 0)
                        t /= j;
                }
                if (t == 1)
                    break;
            }
        }
        return dp[l];
    }
};