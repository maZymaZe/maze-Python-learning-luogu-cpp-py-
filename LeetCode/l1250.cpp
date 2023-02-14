class Solution {
   public:
    bool isGoodArray(vector<int>& nums) {
        int x = nums[0];
        for (auto i : nums)
            x = __gcd(x, i);
        return x == 1;
    }
};