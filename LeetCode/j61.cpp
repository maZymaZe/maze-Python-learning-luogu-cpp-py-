class Solution {
   public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int p = 0;
        while (p < 5 && nums[p] == 0)
            p++;
        if (p == 5)
            return true;
        for (int i = p; i < 4; i++)
            if (nums[i] == nums[i + 1])
                return false;
        if (nums[4] - nums[p] <= 4)
            return true;
        return false;
    }
};