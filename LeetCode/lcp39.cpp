class Solution {
   public:
    int minimumSwitchingTimes(vector<vector<int>>& source,
                              vector<vector<int>>& target) {
        int c1[10002] = {0}, c2[10002] = {0};
        for (auto& i : source) {
            for (auto& j : i) {
                c1[j]++;
            }
        }
        for (auto& i : target) {
            for (auto& j : i) {
                c2[j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < 10002; i++) {
            ans += max(c2[i] - c1[i], 0);
        }
        return ans;
    }
};