class Solution {
   public:
    string nearestPalindromic(string n) {
        int l = n.length();
        vector<long long> a;
        a.push_back((long long)pow(10ll, l) + 1);
        a.push_back((long long)pow(10ll, l - 1) - 1);
        long long pf = stoll(n.substr(0, (l + 1) / 2));
        for (int i = -1; i < 2; i++) {
            string p = to_string(pf + i);
            string pp = p + string(p.rbegin() + (l & 1), p.rend());
            a.push_back(stoll(pp));
        }
        long long t = stoll(n), ans = 0;
        for (long long x : a) {
            if (x == t)
                continue;
            if (abs(x - t) < abs(ans - t))
                ans = x;
            else if (abs(x - t) == abs(ans - t) && x < ans)
                ans = x;
        }
        return to_string(ans);
    }
};