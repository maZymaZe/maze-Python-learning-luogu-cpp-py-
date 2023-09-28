struct PR {
    int x, id;
    bool operator<(const PR& other) const { return x < other.x; }
};
class Solution {
   public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                                 vector<int>& people) {
        vector<PR> as, fs;
        int l = people.size();
        for (int i = 0; i < l; i++) {
            as.push_back({people[i], i});
        }
        for (auto& f : flowers) {
            fs.push_back({f[0], 1});
            fs.push_back({f[1] + 1, -1});
        }
        sort(as.begin(), as.end());
        sort(fs.begin(), fs.end());
        int p1 = 0, p2 = 0, l1 = as.size(), l2 = fs.size(), tot = 0;
        vector<int> ans(l);
        while (p1 < l1 && p2 < l2) {
            if (as[p1].x < fs[p2].x) {
                ans[as[p1].id] = tot;
                p1++;
            } else {
                tot += fs[p2].id;
                p2++;
            }
        }
        return ans;
    }
};