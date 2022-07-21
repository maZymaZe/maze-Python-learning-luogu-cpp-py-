class Solution {
   public:
    int countElements(vector<int>& nums) {
        int ma = -0x3f3f3f3f, mi = 0x3f3f3f3f, ca = 0, ci = 0, l = nums.size();
        for (int i = 0; i < l; i++) {
            if (nums[i] > ma) {
                ma = nums[i];
                ca = 1;
            } else if (nums[i] == ma)
                ca++;
            if (nums[i] < mi)
                mi = nums[i], ci = 1;
            else if (nums[i] == mi)
                ci++;
        }
        if (ma == mi)
            return 0;
        return l - ca - ci;
    }
};