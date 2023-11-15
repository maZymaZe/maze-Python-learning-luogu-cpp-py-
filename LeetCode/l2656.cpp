class Solution {
   public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx = 0;
        for (int i : nums)
            mx = max(mx, i);
        return (mx + mx + k - 1) * k / 2;
    }
};