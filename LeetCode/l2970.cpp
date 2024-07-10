class Solution {
   public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0, l = nums.size();
        for (int i = 0; i < l; i++) {
            for (int j = i; j < l; j++) {
                int pre = -1, ok = 1;
                for (int k = 0; k < l; k++) {
                    if (k >= i && k <= j)
                        continue;
                    if (nums[k] > pre)
                        pre = nums[k];
                    else {
                        ok = 0;
                        break;
                    }
                }
                ans += ok;
            }
        }
        return ans;
    }
};