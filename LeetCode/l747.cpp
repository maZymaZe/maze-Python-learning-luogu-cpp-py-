class Solution {
   public:
    int dominantIndex(vector<int>& nums) {
        int ma = -1, mp = -1, l = nums.size();
        for (int i = 0; i < l; i++) {
            if (nums[i] > ma) {
                ma = nums[i];
                mp = i;
            }
        }
        for (int i = 0; i < l; i++) {
            if (i != mp) {
                if (nums[i] * 2 > ma)
                    return -1;
            }
        }
        return mp;
    }
};