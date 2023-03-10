class Solution {
   public:
    int minSubarray(vector<int>& nums, int p) {
        int tot = 0, l = nums.size(), t = 0;
        int ans = l;
        unordered_map<int, int> mp;
        for (int i = 0; i < l; i++)
            tot = (tot + nums[i]) % p;
        if (!tot)
            return 0;
        mp[0] = -1;
        for (int i = 0; i < l; i++) {
            t = (t + nums[i]) % p;
            int k = (t + p - tot) % p;
            if (mp.count(k)) {
                ans = min(ans, i - mp[k]);
            }
            mp[t] = i;
        }
        if (ans == l)
            return -1;
        return ans;
    }
};