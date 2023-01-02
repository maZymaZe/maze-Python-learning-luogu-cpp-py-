class Solution {
   public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        map<int, int> b, s;
        for (auto& it : orders) {
            if (it[2]) {
                auto i = b.end();
                int c = it[1], v = it[0];
                while (1) {
                    if (!c || i == b.begin())
                        break;
                    --i;
                    if (i->first >= v) {
                        int u = min(c, i->second);
                        c -= u, i->second -= u;
                        if (i->second == 0) {
                            i = b.erase(i);
                        }
                    } else {
                        break;
                    }
                }
                if (c) {
                    s[v] += c;
                }
            } else {
                auto i = s.begin();
                int c = it[1], v = it[0];
                while (1) {
                    if (!c || i == s.end())
                        break;
                    if (i->first <= v) {
                        int u = min(c, i->second);
                        c -= u, i->second -= u;
                        if (i->second == 0) {
                            i = s.erase(i);
                        } else {
                            ++i;
                        }
                    } else {
                        break;
                    }
                }
                if (c) {
                    b[v] += c;
                }
            }
        }
        long long ans = 0, MOD = 1e9 + 7;
        for (auto& it : b) {
            ans += it.second;
            ans %= MOD;
        }
        for (auto& it : s) {
            ans += it.second;
            ans %= MOD;
        }
        return ans;
    }
};