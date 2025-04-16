class Solution {
   public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long ans = 0;
        int n = nums.size();
        long long cur = 0, p = 0;
        for (int i = 0; i < n; i++) {
            cur += mp[nums[i]];
            mp[nums[i]]++;
            while (cur >= k) {
                mp[nums[p]]--;
                cur -= mp[nums[p]];
                p++;
            }
            ans += p;
        }
        return ans;
    }
};