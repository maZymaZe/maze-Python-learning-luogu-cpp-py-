class Solution {
   public:
    vector<int> minSubsequence(vector<int>& nums) {
        int tot = 0, t = 0;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int l = nums.size();
        for (int i = l - 1; i >= 0; i--) {
            tot += nums[i];
        }
        for (int i = l - 1; i >= 0; i--) {
            ans.push_back(nums[i]);
            t += nums[i];
            if (t > tot - t)
                break;
        }
        return ans;
    }
};