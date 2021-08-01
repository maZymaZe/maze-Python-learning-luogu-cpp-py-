class Solution {
   public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        int l = groupSizes.size();
        vector<int> fp(l + 1);
        for (int i = 0; i < l; i++) {
            if (fp[groupSizes[i]] == 0) {
                ans.push_back(vector<int>());
                fp[groupSizes[i]] = ans.size();
            }
            ans[fp[groupSizes[i]] - 1].push_back(i);
            if (ans[fp[groupSizes[i]] - 1].size() == groupSizes[i]) {
                fp[groupSizes[i]] = 0;
            }
        }
        return ans;
    }
};