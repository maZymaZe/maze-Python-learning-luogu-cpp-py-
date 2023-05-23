struct PR {
    int v, l;
};
class Solution {
   public:
    int largestValsFromLabels(vector<int>& values,
                              vector<int>& labels,
                              int numWanted,
                              int useLimit) {
        int l = values.size(), ans = 0, sz = 0;

        vector<PR> v;
        for (int i = 0; i < l; i++)
            v.push_back({values[i], labels[i]});
        sort(v.begin(), v.end(), [&](const PR& v1, const PR& v2) {
            return v1.v == v2.v ? v1.l > v2.l : v1.v > v2.v;
        });
        unordered_map<int, int> ml;
        for (int i = 0; i < l; i++) {
            if (ml[v[i].l] < useLimit) {
                ans += v[i].v;
                sz++;
                ml[v[i].l]++;
            }
            if (sz == numWanted) {
                break;
            }
        }
        return ans;
    }
};