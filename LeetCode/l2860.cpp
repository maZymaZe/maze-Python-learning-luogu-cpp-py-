class Solution {
   public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int tot = 0, l = nums.size();
        for (int i = 0; i < l - 1; i++) {
            if (nums[i] < i + 1 && i + 1 < nums[i + 1])
                tot++;
        }
        if (nums[0] != 0)
            tot++;
        if (l > nums[l - 1])
            tot++;
        return tot;
    }
};