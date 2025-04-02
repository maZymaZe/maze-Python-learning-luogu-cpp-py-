class Solution {
   public:
    long long maximumTripletValue(vector<int>& nums) {
        int l = nums.size();
        int m = nums[l - 1];
        vector<int> mx(l);
        for (int i = l - 2; i > 0; i--) {
            mx[i] = m;
            m = max(m, nums[i]);
        }
        m = nums[0];
        long long ans = 0;
        for (int i = 1; i < l - 1; i++) {
            ans = max(ans, (long long)(m - nums[i]) * mx[i]);
            m = max(m, nums[i]);
        }
        return ans;
    }
};