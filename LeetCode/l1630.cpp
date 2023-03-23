class Solution {
   public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums,
                                          vector<int>& l,
                                          vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<int> v(n);
        vector<bool> ans(m);
        for (int i = 0; i < m; i++) {
            int ma, mi;
            ma = mi = nums[l[i]];
            for (int j = l[i]; j <= r[i]; j++) {
                ma = max(ma, nums[j]);
                mi = min(mi, nums[j]);
                v[j] = 0;
            }
            if ((ma - mi) % (r[i] - l[i])) {
                ans[i] = 0;
                continue;
            }
            int b = (ma - mi) / (r[i] - l[i]);
            if (b == 0) {
                ans[i] = 1;
                continue;
            }
            int suc = 1;
            for (int j = l[i]; j <= r[i]; j++) {
                int x = nums[j] - mi;
                if (x % b) {
                    suc = 0;
                    break;
                }
                x /= b;
                if (v[l[i] + x]) {
                    suc = 0;
                    break;
                } else
                    v[l[i] + x] = 1;
            }
            ans[i] = suc;
        }
        return ans;
    }
};