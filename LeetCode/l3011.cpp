class Solution {
   public:
    bool canSortArray(vector<int>& nums) {
        int pre = 0, c = 0, l = nums.size();
        int t = nums[0];
        while (t) {
            c += t % 2;
            t /= 2;
        }
        for (int i = 1; i < l; i++) {
            t = nums[i];
            int tc = 0;
            while (t) {
                tc += t % 2;
                t /= 2;
            }
            if (tc != c) {
                sort(nums.begin() + pre, nums.begin() + i);
                pre = i;
                c = tc;
            }
        }
        sort(nums.begin() + pre, nums.end());
        for (int i = 1; i < l; i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }
};