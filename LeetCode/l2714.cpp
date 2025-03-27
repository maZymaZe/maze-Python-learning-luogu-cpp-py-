class Solution {
   public:
    long long minimumCost(string s) {
        vector<int> t;
        int l = s.size(), c = 1;
        for (int i = 1; i < l; i++) {
            if (s[i] == s[i - 1]) {
                c++;
            } else {
                t.push_back(c);
                c = 1;
            }
        }
        t.push_back(c);
        l = t.size();
        int p = 0, q = l - 1;
        long long ans = 0;
        for (int i = 1; i < l; i++) {
            if (t[p] < t[q]) {
                ans += t[p];
                t[p + 1] += t[p];
                p++;
            } else {
                ans += t[q];
                t[q - 1] += t[q];
                q--;
            }
        }
        return ans;
    }
};