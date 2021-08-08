class Solution {
   public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, l = nums.size(), bs = 0;
        for (int i = 1; i < l; i++) {
            if (nums[i] != nums[i - 1])
                bs++;
            ans += bs;
        }
        return ans;
    }
};