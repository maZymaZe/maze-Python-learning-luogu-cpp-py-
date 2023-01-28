class Solution {
   public:
    vector<bool> distanceLimitedPathsExist(int n,
                                           vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {
        int l = queries.size();
        for (int i = 0; i < l; i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });
        vector<int> f(n);
        for (int i = 0; i < n; i++)
            f[i] = i;
        function<int(int)> ff = [&](int x) {
            return f[x] == x ? x : f[x] = ff(f[x]);
        };
        sort(edgeList.begin(), edgeList.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });
        vector<bool> ans(l);
        int p = 0, el = edgeList.size();
        for (int i = 0; i < l; i++) {
            while (p < el && edgeList[p][2] < queries[i][2]) {
                int x = edgeList[p][0], y = edgeList[p][1];
                f[ff(x)] = ff(y);
                p++;
            }
            ans[queries[i][3]] = (ff(queries[i][0]) == ff(queries[i][1]));
        }
        return ans;
    }
};