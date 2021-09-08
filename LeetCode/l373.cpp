struct pr {
    int id, pos, tot;
    bool operator<(const pr& x) const { return tot > x.tot; }
};
class Solution {
   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2,
                                       int k) {
        int l1 = nums1.size(), l2 = nums2.size();
        vector<vector<int>> ans;
        if (k >= 1ll * l1 * l2) {
            for (int i = 0; i < l1; i++) {
                for (int j = 0; j < l2; j++) {
                    ans.push_back({nums1[i], nums2[j]});
                }
            }
            return ans;
        }
        priority_queue<pr> q;
        for (int i = 0; i < l1; i++) {
            q.push({nums1[i], 0, nums2[0] + nums1[i]});
        }
        for (int i = 0; i < k; i++) {
            pr ot = q.top();
            ans.push_back({ot.id, nums2[ot.pos]});
            q.pop();
            if (ot.pos != l2 - 1) {
                q.push({ot.id, ot.pos + 1, ot.id + nums2[ot.pos + 1]});
            }
        }
        return ans;
    }
};