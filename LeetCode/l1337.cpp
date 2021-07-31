struct pr {
    int c, id;
    bool operator<(const pr& x) const { return c == x.c ? id < x.id : c < x.c; }
};
class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<pr> v(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j])
                    v[i].c++;
            }
            v[i].id = i;
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(v[i].id);
        return ans;
    }
};