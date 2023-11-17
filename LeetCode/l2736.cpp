struct PR {
    int a, b;
    bool operator<(const PR& other) const {
        return a == other.a ? b < other.b : (a < other.a);
    }
};
class Solution {
   public:
    vector<int> maximumSumQueries(vector<int>& nums1,
                                  vector<int>& nums2,
                                  vector<vector<int>>& queries) {
        int ql = queries.size(), l = nums1.size();
        for (int i = 0; i < ql; i++)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] > b[0];
             });
        vector<PR> points(l);
        for (int i = 0; i < l; i++) {
            points[i] = {nums1[i], nums2[i]};
        }
        sort(points.begin(), points.end(), [](const PR& a, const PR& b) {
            return (a.a == b.a) ? a.b > b.b : a.a > b.a;
        });
        vector<PR> st;
        vector<int> ans(ql, -1);
        int p = 0;
        for (int i = 0; i < ql; i++) {
            while (p < l && points[p].a >= queries[i][0]) {
                int tot = points[p].a + points[p].b, tb = points[p].b;
                while (!st.empty() && st.back().b <= tot) {
                    st.pop_back();
                }
                if (st.empty() || st.back().a < tb) {
                    st.push_back({tb, tot});
                }
                p++;
            }
            int k = lower_bound(st.begin(), st.end(), (PR){queries[i][1], 0}) -
                    st.begin();
            if (k < st.size()) {
                ans[queries[i][2]] = st[k].b;
            }
        }
        return ans;
    }
};