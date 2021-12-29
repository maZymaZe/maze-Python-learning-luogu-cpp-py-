class Solution {
   public:
    int countQuadruplets(vector<int>& nums) {
        int l = nums.size(), ans = 0;
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                for (int k = j + 1; k < l; k++) {
                    for (int n = k + 1; n < l; n++) {
                        ans += (nums[i] + nums[j] + nums[k] == nums[n]);
                    }
                }
            }
        }
        return ans;
    }
};