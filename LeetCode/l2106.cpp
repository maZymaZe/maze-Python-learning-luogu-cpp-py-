class Solution {
   public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int tot = 0, l = fruits.size();
        map<int, int> ps;
        ps[-300000] = 0;
        for (int i = 0; i < l; i++) {
            tot += fruits[i][1];
            ps[fruits[i][0]] = tot;
        }
        int ans = 0;
        auto it = ps.upper_bound(startPos);
        if (it != ps.begin()) {
            --it;
            auto it2 = ps.lower_bound(startPos - k);
            --it2;
            ans = max(it->second - it2->second, ans);
        }
        for (int i = 0; i < l; i++) {
            if (fruits[i][0] <= startPos || fruits[i][0] > startPos + k)
                continue;
            int dis = fruits[i][0] - startPos;
            int lm = min(startPos - (k - 2 * dis), startPos - (k - dis) / 2);
            auto it2 = ps.lower_bound(lm);
            --it2;
            ans = max(ans, ps[fruits[i][0]] - it2->second);
        }
        return ans;
    }
};