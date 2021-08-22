class Solution {
   public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int l = nums.size();
        if (l == 1)
            return -1;
        sort(nums.begin(), nums.end());
        int ll = 0, rr = 1;
        int ans = -1;
        while (rr < l && nums[ll] + nums[rr] < k) {
            ans = max(ans, nums[ll] + nums[rr]);
            rr++;
        }
        ll++;
        if (rr == l)
            rr--;
        while (ll < rr) {
            while (rr > ll && nums[ll] + nums[rr] >= k)
                rr--;
            if (rr > ll)
                ans = max(ans, nums[ll] + nums[rr]);
            ll++;
        }
        return ans;
    }
};