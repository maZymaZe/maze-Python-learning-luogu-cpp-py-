class Solution {
   public:
    vector<string> ans;
    int op[300] = {0}, ll;
    int u[8] = {'0', '1', '8', '6', '9'};
    string ss;
    void dfs(int p, int t) {
        if (p == t) {
            for (int i = 0; i < t; i++) {
                ss[ll - i - 1] = op[ss[i]];
            }
            ans.push_back(ss);
            return;
        }
        for (int i = (p == 0); i < 5; i++) {
            ss[p] = u[i];
            dfs(p + 1, t);
        }
    }
    vector<string> findStrobogrammatic(int n) {
        ll = n;
        op['0'] = '0';
        op['1'] = '1';
        op['6'] = '9';
        op['9'] = '6';
        op['8'] = '8';

        if (n == 1) {
            string s(1, '1');
            for (int i = 0; i < 3; i++) {
                s[0] = u[i];
                ans.push_back(s);
            }
            return ans;
        }
        ss.resize(n);
        if (n & 1)
            for (int i = 0; i < 3; i++) {
                ss[n / 2] = u[i];
                dfs(0, n / 2);
            }
        else
            dfs(0, n / 2);
        return ans;
    }
};