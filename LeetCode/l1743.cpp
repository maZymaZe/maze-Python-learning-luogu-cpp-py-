class Solution {
   public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int len = adjacentPairs.size() + 1;
        vector<int> ans(len);
        unordered_map<int, int> a, b;
        for (int i = 0; i < len - 1; i++) {
            if (a.count(adjacentPairs[i][0]))
                b[adjacentPairs[i][0]] = adjacentPairs[i][1];
            else
                a[adjacentPairs[i][0]] = adjacentPairs[i][1];
            if (a.count(adjacentPairs[i][1]))
                b[adjacentPairs[i][1]] = adjacentPairs[i][0];
            else
                a[adjacentPairs[i][1]] = adjacentPairs[i][0];
        }
        for (int i = 0; i < len - 1; i++) {
            if (!b.count(adjacentPairs[i][0])) {
                ans[0] = adjacentPairs[i][0];
                break;
            }
            if (!b.count(adjacentPairs[i][1])) {
                ans[0] = adjacentPairs[i][1];
                break;
            }
        }
        ans[1] = a[ans[0]];
        for (int i = 2; i < len; i++) {
            if (a[ans[i - 1]] == ans[i - 2])
                ans[i] = b[ans[i - 1]];
            else
                ans[i] = a[ans[i - 1]];
        }
        return ans;
    }
};