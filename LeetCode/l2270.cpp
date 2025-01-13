class Solution {
   public:
    int waysToSplitArray(vector<int>& nums) {
        long long tot = 0, c = 0;
        int ans = 0, l = nums.size();
        for (int i : nums)
            tot += i;
        for (int i = 0; i < l - 1; i++) {
            c += nums[i];
            if (c >= tot - c)
                ans++;
        }
        return ans;
    }
};