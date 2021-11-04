class Solution {
   public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (auto i : arr) {
            if (mp.count(i - difference)) {
                mp[i] = max(mp[i], mp[i - difference] + 1);
                ans = max(ans, mp[i]);
            } else {
                mp[i] = max(mp[i], 1);
                ans = max(ans, mp[i]);
            }
        }
        return ans;
    }
};