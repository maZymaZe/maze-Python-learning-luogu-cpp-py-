class Solution {
   public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int val = 0, n = nums.size();
        vector<int> ps = nums, ans(n);
        for (int i = n - 2; i >= 0; i--) {
            ps[i] |= ps[i + 1];
        }
        int r = 1;
        int c[40] = {0};
        int p = 0, x = nums[0];
        while (x) {
            if (x & 1) {
                c[p]++;
                if (c[p] == 1)
                    val |= (1 << p);
            }
            x >>= 1;
            p++;
        }
        for (int l = 0; l < n; l++) {
            while (val < ps[l]) {
                p = 0, x = nums[r];
                while (x) {
                    if (x & 1) {
                        c[p]++;
                        if (c[p] == 1)
                            val |= (1 << p);
                    }
                    x >>= 1;
                    p++;
                }
                r++;
            }
            ans[l] = max(r - l, 1);
            x = nums[l], p = 0;
            while (x) {
                if (x & 1) {
                    c[p]--;
                    if (c[p] == 0)
                        val ^= (1 << p);
                }
                x >>= 1;
                p++;
            }
        }
        return ans;
    }
};