class Solution {
   public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        int cur = INT_MIN, ans = 0;
        for (auto x : pairs) {
            if (x[0] > cur) {
                cur = x[1];
                ans++;
            }
        }
        return ans;
    }
};