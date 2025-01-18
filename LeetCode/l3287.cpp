class Solution {
   public:
    int maxValue(vector<int>& nums, int k) {
        int dpl[2][128][210] = {0};
        int l = nums.size();
        int lans[128] = {0}, rans[128] = {0};
        dpl[1][0][0] = 1;
        for (int i = 0; i < l; i++) {
            memset(dpl[i & 1], 0, sizeof(dpl[i & 1]));
            for (int j = 0; j <= k; j++) {
                for (int m = 0; m < 128; m++) {
                    dpl[i & 1][m | nums[i]][j + 1] |= dpl[(i & 1) ^ 1][m][j];
                    dpl[i & 1][m][j] |= dpl[(i & 1) ^ 1][m][j];
                }
            }
            for (int m = 0; m < 128; m++) {
                if (lans[m] == 0 && dpl[i & 1][m][k])
                    lans[m] = i + 1;
            }
        }
        memset(dpl, 0, sizeof(dpl));
        reverse(nums.begin(), nums.end());
        dpl[1][0][0] = 1;
        for (int i = 0; i < l; i++) {
            memset(dpl[i & 1], 0, sizeof(dpl[i & 1]));
            for (int j = 0; j <= k; j++) {
                for (int m = 0; m < 128; m++) {
                    dpl[i & 1][m | nums[i]][j + 1] |= dpl[(i & 1) ^ 1][m][j];
                    dpl[i & 1][m][j] |= dpl[(i & 1) ^ 1][m][j];
                }
            }
            for (int m = 0; m < 128; m++) {
                if (rans[m] == 0 && dpl[i & 1][m][k])
                    rans[m] = i + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                if (lans[i] + rans[j] <= l && lans[i] && rans[j]) {
                    ans = max(ans, (i ^ j));
                }
            }
        }
        return ans;
    }
};