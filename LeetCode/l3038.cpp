class Solution {
   public:
    int maxOperations(vector<int>& nums) {
        int l = nums.size(), ans = 1, t = nums[0] + nums[1];
        for (int i = 2; i + 1 < l; i += 2) {
            if (nums[i] + nums[i + 1] == t)
                ans++;
            else
                break;
        }
        return ans;
    }
};