class Solution {
   public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int res = 0, tot = 0;
        for (char c : s) {
            if (res < widths[c - 'a'])
                res = 100, tot++;
            res -= widths[c - 'a'];
        }
        return {tot, 100 - res};
    }
};