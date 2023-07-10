class Solution {
   public:
    long long maxAlternatingSum(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        long long t1 = max(nums[0], nums[1]), t2 = nums[0] - nums[1];
        int l = nums.size();
        for (int i = 2; i < l; i++) {
            long long nt1, nt2;
            nt1 = max(t1, t2 + nums[i]);
            nt1 = max(nt1, (long long)nums[i]);
            nt2 = max(t2, t1 - nums[i]);
            t1 = nt1, t2 = nt2;
        }
        return max(t1, t2);
    }
};