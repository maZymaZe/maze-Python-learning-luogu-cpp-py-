class Solution {
   public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = (long long)n * (n - 1) / 2;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            ans -= mp[diff];
            mp[diff]++;
        }
        return ans;
    }
};