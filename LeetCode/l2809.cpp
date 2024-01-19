struct PR {
    int a, b;
    bool operator<(const PR& o) {
        if (b == o.b)
            return a > o.a;
        return b < o.b;
    }
};
class Solution {
   public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int l = nums1.size();
        vector<PR> gp(l);
        for (int i = 0; i < l; i++)
            gp[i] = {nums1[i], nums2[i]};
        sort(gp.begin(), gp.end());
        vector<vector<int>> dp(l + 1, vector<int>(l));
        vector<int> mx(l), tmx(l + 1);
        for (int i = 1; i <= l; i++) {
            for (int j = 0; j < l; j++) {
                dp[i][j] = mx[j] + gp[j].a + i * gp[j].b;
                tmx[i] = max(tmx[i], dp[i][j]);
            }
            for (int j = 1; j < l; j++) {
                mx[j] = max(mx[j - 1], dp[i][j - 1]);
            }
        }
        int tot1 = 0, tot2 = 0;
        for (int i = 0; i < l; i++) {
            tot1 += gp[i].a, tot2 += gp[i].b;
        }
        if (tot1 <= x)
            return 0;
        for (int i = 1; i <= l; i++) {
            tot1 += tot2;
            if (tot1 - tmx[i] <= x)
                return i;
        }
        return -1;
    }
};