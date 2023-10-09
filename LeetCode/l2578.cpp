class Solution {
   public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int l = s.length(), ans = 0;
        for (int i = 0; i < l; i++) {
            ans += pow(10, i / 2) * (s[l - i - 1] - '0');
        }
        return ans;
    }
};