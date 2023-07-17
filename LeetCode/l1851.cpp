class Solution {
   public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {
        set<int> q;
        map<int, int> ans;
        vector<int> rs;
        for (int i : queries) {
            q.insert(i);
        }
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] - a[0] < b[1] - b[0];
             });
        for (const auto& v : intervals) {
            int sz = v[1] - v[0] + 1;
            auto it = q.lower_bound(v[0]);
            while (it != q.end() && *it <= v[1]) {
                ans[*it] = sz;
                it = q.erase(it);
            }
        }
        for (int i : q)
            ans[i] = -1;
        for (int i : queries) {
            rs.push_back(ans[i]);
        }
        return rs;
    }
};