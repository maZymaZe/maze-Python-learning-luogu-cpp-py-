class Solution {
   public:
    bool isArraySpecial(vector<int>& nums) {
        int l = nums.size();
        for (int i = 1; i < l; i++)
            if ((nums[i] & 1) == (nums[i - 1] & 1))
                return false;
        return true;
    }
};