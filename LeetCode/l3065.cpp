class Solution {
   public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for (int i : nums)
            ans += (i < k);
        return ans;
    }
};