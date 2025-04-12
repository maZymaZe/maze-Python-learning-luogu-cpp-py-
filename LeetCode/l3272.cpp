class Solution {
   public:
    long long countGoodIntegers(int n, int k) {
        int be = pow(10, (n - 1) / 2), ed = pow(10, (n + 1) / 2) - 1;
        vector<string> vs;
        for (int i = be; i <= ed; i++) {
            string s = to_string(i);
            string t = s;
            reverse(t.begin(), t.end());
            if (n % 2 == 0) {
                s += t;
            } else {
                s += t.substr(1);
            }
            long long u = stoll(s);
            if (u % k)
                continue;
            sort(s.begin(), s.end());
            vs.push_back(s);
        }
        sort(vs.begin(), vs.end());
        int ls = vs.size();
        long long ans = 0, rm[11] = {0};
        rm[0] = 1;
        for (int i = 1; i <= n; i++)
            rm[i] = rm[i - 1] * i;
        for (int i = 0; i < ls; i++) {
            if (i && vs[i] == vs[i - 1])
                continue;
            int cnt[10] = {0};
            for (char c : vs[i]) {
                cnt[c - '0']++;
            }
            long long cur = rm[n];
            for (int j = 0; j < 10; j++) {
                cur /= rm[cnt[j]];
            }
            ans += cur;
            if (cnt[0] > 0) {
                cnt[0]--;
                cur = rm[n - 1];
                for (int j = 0; j < 10; j++) {
                    cur /= rm[cnt[j]];
                }
                ans -= cur;
            }
        }
        return ans;
    }
};