class Solution {
   public:
    int minimumMountainRemovals(vector<int>& nums) {
        int l = nums.size();
        vector<int> v, lm(l), rm(l);
        for (int i = 0; i < l; i++) {
            auto it = lower_bound(v.begin(), v.end(), nums[i]);
            if (it == v.end()) {
                v.push_back(nums[i]);
                lm[i] = v.size();
            } else {
                *it = nums[i];
                lm[i] = it - v.begin() + 1;
            }
        }
        reverse(nums.begin(), nums.end());
        v.clear();
        for (int i = 0; i < l; i++) {
            auto it = lower_bound(v.begin(), v.end(), nums[i]);
            if (it == v.end()) {
                v.push_back(nums[i]);
                rm[i] = v.size();
            } else {
                *it = nums[i];
                rm[i] = it - v.begin() + 1;
            }
        }
        int ans = 0;
        reverse(rm.begin(), rm.end());
        for (int i = 1; i < l - 1; i++) {
            if (lm[i] > 1 && rm[i] > 1) {
                ans = max(ans, (rm[i] + lm[i] - 1));
            }
        }
        return l - ans;
    }
};
