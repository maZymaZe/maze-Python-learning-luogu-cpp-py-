class Solution {
   public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (string& w : words) {
            int t = 0;
            for (char c : w) {
                t |= (1 << (c - 'a'));
            }
            ans += mp[t];
            mp[t]++;
        }
        return ans;
    }
};