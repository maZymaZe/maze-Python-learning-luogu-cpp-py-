class Solution {
   public:
    string convert(string s, int numRows) {
        int st = 0, p = 0;
        if (numRows == 1)
            return s;
        vector<string> e;
        e.resize(numRows);
        for (char c : s) {
            if (st == 0) {
                e[p++] += c;
                if (p == numRows) {
                    st = 1;
                    p -= 2;
                }
            } else {
                e[p--] += c;
                if (p < 0) {
                    st = 0;
                    p += 2;
                }
            }
        }
        string ans;
        for (string& x : e)
            ans += x;
        return ans;
    }
};