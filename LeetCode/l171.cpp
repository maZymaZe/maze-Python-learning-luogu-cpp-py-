class Solution {
   public:
    int titleToNumber(string columnTitle) {
        int l = columnTitle.size(), ans = 0;
        long long t = 1;
        for (int i = l - 1; i >= 0; i--) {
            ans += (columnTitle[i] - 'A' + 1) * t;
            t *= 26;
        }
        return ans;
    }
};