struct PR {
    int q, id;
    bool operator<(const PR& x) const { return q < x.q; }
};
class Solution {
   public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        vector<PR> v;
        int l = queries.size();
        for (int i = 0; i < l; i++) {
            v.push_back({queries[i], i});
        }
        sort(v.begin(), v.end());
        int ma = 0;
        int il = items.size(), p = 0;
        vector<int> ans(l);
        for (int i = 0; i < il; i++) {
            while (p < l && v[p].q < items[i][0]) {
                ans[v[p].id] = ma;
                p++;
            }
            ma = max(ma, items[i][1]);
        }
        while (p < l) {
            ans[v[p].id] = ma;
            p++;
        }
        return ans;
    }
};