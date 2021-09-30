class Solution {
   public:
    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 1)
            return to_string(nums[0]);
        if (nums.size() == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        string ans;
        ans += to_string(nums[0]) + "/(" + to_string(nums[1]);
        int l = nums.size();
        for (int i = 2; i < l; i++)
            ans += "/" + to_string(nums[i]);
        ans += ")";
        return ans;
    }
};