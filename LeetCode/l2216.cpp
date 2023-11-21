class Solution {
   public:
    int minDeletion(vector<int>& nums) {
        int pre = nums[0], f = 0, l = nums.size(), tot = 0;
        for (int i = 1; i < l; i++) {
            if (!f) {
                if (nums[i] == pre) {
                    tot++;
                    continue;
                } else {
                    f = 1;
                }
            } else {
                f = 0;
                pre = nums[i];
            }
        }
        if (!f)
            tot++;
        return tot;
    }
};