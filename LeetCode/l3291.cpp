struct NODE {
    int nx[26] = {0};
};
class Solution {
   public:
    vector<NODE> v;
    vector<int> dp;
    void insert(const string& x) {
        int p = 0, l = x.size();
        for (int i = 0; i < l; i++) {
            if (v[p].nx[x[i] - 'a'] == 0) {
                v[p].nx[x[i] - 'a'] = v.size();
                v.push_back(NODE{});
            }
            p = v[p].nx[x[i] - 'a'];
        }
    }
    int minValidStrings(vector<string>& words, string target) {
        dp.resize(target.length() + 1, 0x3f3f3f3f);
        dp[0] = 0;
        v.resize(1);
        for (const string& s : words) {
            insert(s);
        }
        int l = target.size();
        for (int i = 0; i < l; i++) {
            int p = 0;
            for (int j = i + 1; j <= l; j++) {
                if (v[p].nx[target[j - 1] - 'a']) {
                    dp[j] = min(dp[j], dp[i] + 1);
                    p = v[p].nx[target[j - 1] - 'a'];
                } else
                    break;
            }
        }
        return dp[target.size()] < 0x3f3f3f3f ? dp[target.size()] : -1;
    }
};