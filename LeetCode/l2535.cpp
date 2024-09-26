class Solution {
   public:
    int differenceOfSum(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) {
            ans += i;
            while (i) {
                ans -= (i % 10);
                i /= 10;
            }
        }
        return ans;
    }
};