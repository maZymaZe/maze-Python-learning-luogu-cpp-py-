class Solution {
   public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size(), a, b;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                a = i;
            if (nums[i] == n)
                b = i;
        }
        return a + (n - 1 - b) - (a > b);
    }
};