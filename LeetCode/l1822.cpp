class Solution {
   public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (int i : nums) {
            if (i == 0)
                ans = 0;
            if (i < 0)
                ans *= -1;
        }
        return ans;
    }
};