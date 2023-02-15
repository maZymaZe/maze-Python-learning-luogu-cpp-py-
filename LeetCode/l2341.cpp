class Solution {
   public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int l = nums.size(), ans = 0;
        map<int, int> m;
        for (auto x : nums) {
            m[x]++;
        }
        for (auto it : m) {
            ans += it.second / 2;
        }
        return {ans, l - 2 * ans};
    }
};