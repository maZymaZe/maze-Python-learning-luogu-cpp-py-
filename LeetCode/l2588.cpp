class Solution {
   public:
    long long beautifulSubarrays(vector<int>& nums) {
        map<int, int> mp;
        mp[0] = 1;
        long long ans = 0, t = 0;
        for (int i : nums) {
            t ^= i;
            ans += mp[t];
            mp[t]++;
        }
        return ans;
    }
};