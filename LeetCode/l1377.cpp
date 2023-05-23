class Solution {
   public:
    vector<vector<int>> cn;
    vector<int> de;
    vector<int> s;
    int tg, st;
    double ans = 0;
    void dfs(int x, int f) {
        for (int i : cn[x]) {
            if (i != f) {
                if (i == tg) {
                    if (tg != 0 && de[tg] == 1 && s.size() <= st) {
                        ans = 1.0 / de[0];
                        int sz = s.size();
                        for (int j = 1; j < sz; j++) {
                            ans /= (de[s[j]] - 1);
                        }
                    } else if (s.size() == st) {
                        ans = 1.0 / de[0];
                        for (int j = 1; j < st; j++) {
                            ans /= (de[s[j]] - 1);
                        }
                    }
                } else {
                    s.push_back(i);
                    dfs(i, x);
                    s.pop_back();
                }
            }
        }
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if (n == 1)
            return 1;
        cn.resize(n);
        de.resize(n);
        tg = target - 1, st = t;
        for (auto& v : edges) {
            cn[v[0] - 1].push_back(v[1] - 1);
            cn[v[1] - 1].push_back(v[0] - 1);
            de[v[0] - 1]++, de[v[1] - 1]++;
        }
        s.push_back(0);
        dfs(0, -1);
        return ans;
    }
};