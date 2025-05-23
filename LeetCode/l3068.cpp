class Solution {
   public:
    long long maximumValueSum(vector<int>& nums,
                              int k,
                              vector<vector<int>>& edges) {
        long long f0 = 0, f1 = LLONG_MIN;
        for (int x : nums) {
            long long t = max(f1 + x, f0 + (x ^ k));
            f0 = max(f0 + x, f1 + (x ^ k));
            f1 = t;
        }
        return f0;
    }
};
