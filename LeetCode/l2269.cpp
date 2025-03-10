class Solution {
   public:
    int s2i(const string& s) {
        int ret = 0;
        for (char c : s) {
            ret = ret * 10 + c - '0';
        }
        return ret;
    }
    int divisorSubstrings(int num, int k) {
        string ns = to_string(num);
        int l = ns.size(), ans = 0;
        for (int i = 0; i + k <= l; i++) {
            int x = s2i(ns.substr(i, k));
            if (x && num % x == 0)
                ans++;
        }
        return ans;
    }
};