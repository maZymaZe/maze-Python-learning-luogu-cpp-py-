class Solution {
   public:
    int alternatingSubarray(vector<int>& nums) {
        int c = 0, mx = 0, l = nums.size();

        for (int i = 0; i < l; i++) {
            c = 1;
            int t = 1;
            for (int j = i + 1; j < l; j++) {
                if (nums[j] == nums[j - 1] + t) {
                    c++;
                } else
                    break;
                t *= -1;
            }
            mx = max(mx, c);
        }
        if (mx < 2)
            return -1;
        return mx;
    }
};