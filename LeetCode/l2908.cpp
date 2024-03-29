class Solution {
   public:
    int minimumSum(vector<int>& nums) {
        int l = nums.size();
        vector<int> lv(l), rv(l);
        lv[0] = nums[0], rv[l - 1] = nums[l - 1];
        for (int i = 1; i < l; i++)
            lv[i] = min(lv[i - 1], nums[i]);
        for (int i = l - 2; i >= 0; i--)
            rv[i] = min(rv[i + 1], nums[i]);
        int ans = 0x3f3f3f3f;
        for (int i = 1; i < l - 1; i++) {
            if (lv[i - 1] < nums[i] && rv[i + 1] < nums[i]) {
                ans = min(ans, nums[i] + lv[i - 1] + rv[i + 1]);
            }
        }
        if (ans == 0x3f3f3f3f)
            return -1;
        return ans;
    }
};