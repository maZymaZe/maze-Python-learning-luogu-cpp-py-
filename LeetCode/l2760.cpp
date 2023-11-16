class Solution {
   public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int l = nums.size(), ml = 0, nl = 0;
        if (nums[0] <= threshold && (nums[0] & 1) == 0)
            ml = nl = 1;
        for (int i = 1; i < l; i++) {
            if (nums[i] > threshold)
                nl = 0;
            else if (nl != 0 && (nums[i] & 1) != (nums[i - 1] & 1)) {
                nl++;
                ml = max(ml, nl);
            } else if ((nums[i] & 1) == 0) {
                nl = 1;
                ml = max(ml, 1);
            } else {
                nl = 0;
            }
        }
        return ml;
    }
};