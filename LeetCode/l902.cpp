class Solution {
   public:
    string nb;
    int len, vl;
    vector<int> v;
    vector<long long> pw;
    int ans;
    void dfs(int p) {
        for (int i = 0; i < vl; i++) {
            if (v[i] < nb[p] - '0') {
                ans += pw[len - p - 1];
            } else if (v[i] == nb[p] - '0') {
                if (p != len - 1)
                    dfs(p + 1);
                else
                    ans++;
            } else
                break;
        }
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        nb = to_string(n);
        ans = 0;
        len = nb.size();
        for (auto& it : digits)
            v.push_back(it[0] - '0');
        sort(v.begin(), v.end());
        vl = v.size();
        pw.push_back(1);
        for (int i = 1; i <= 10; i++) {
            pw.push_back(pw.back() * vl);
        }
        dfs(0);

        for (int i = 1; i <= len - 1; i++) {
            ans += pw[i];
        }

        return ans;
    }
};