struct QR {
    int l, r, id;
    bool operator<(const QR& other) const { return l < other.l; }
};
class Solution {
   public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int ql = queries.size(), l = nums.size();
        vector<QR> qv;
        vector<bool> ans(ql);
        for (int i = 0; i < ql; i++) {
            qv.push_back({queries[i][0], queries[i][1], i});
        }
        sort(qv.begin(), qv.end());
        int cl = 0, cr = 0;
        while (cr < l &&
               (((nums[cl] & 1) ^ (nums[cr] & 1) ^ ((cr - cl) & 1)) == 0))
            cr++;
        for (int i = 0; i < ql; i++) {
            while (qv[i].l >= cr) {
                cl = cr;
                while (cr < l && (((nums[cl] & 1) ^ (nums[cr] & 1) ^
                                   ((cr - cl) & 1)) == 0))
                    cr++;
            }
            if (qv[i].r >= cr) {
                ans[qv[i].id] = false;
            } else
                ans[qv[i].id] = true;
        }
        return ans;
    }
};