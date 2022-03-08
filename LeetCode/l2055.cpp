
class Solution {
   public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int l = s.length(), len = queries.size(), cnt = 0;
        map<int, int> mp;
        vector<int> ans(len);
        for (int i = 0; i < l; i++) {
            if (s[i] == '|') {
                mp[i] = ++cnt;
            }
        }
        for (int i = 0; i < len; i++) {
            auto it = mp.lower_bound(queries[i][0]);
            if (it == mp.end()) {
                ans[i] = 0;
                continue;
            }
            auto it2 = mp.upper_bound(queries[i][1]);
            if (it2 != mp.begin()) {
                --it2;
            }
            ans[i] =
                max(it2->first - it->first - (it2->second - it->second), 0);
        }
        return ans;
    }
};
