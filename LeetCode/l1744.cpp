class Solution {
   public:
    vector<bool> canEat(vector<int>& candiesCount,
                        vector<vector<int>>& queries) {
        int l = candiesCount.size(), ql = queries.size();
        vector<long long> ps(l + 1);
        ps[0] = 0;
        for (int i = 0; i < l; i++) {
            ps[i + 1] = ps[i] + candiesCount[i];
        }
        vector<bool> ans(ql);
        for (int i = 0; i < ql; i++) {
            ans[i] = (ps[queries[i][0]]+candiesCount[queries[i][0]] >= (queries[i][1] + 1)) &&
                     (ps[queries[i][0]] + 1 <=
                      (long long)(queries[i][1] + 1) * queries[i][2]);
        }
        return ans;
    }
};