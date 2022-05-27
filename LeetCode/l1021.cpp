class Solution {
   public:
    string removeOuterParentheses(string s) {
        int c = 0;
        string ans;
        for (char a : s) {
            if (a == '(') {
                if (c)
                    ans += a;
                c++;
            } else {
                c--;
                if (c)
                    ans += a;
            }
        }
        return ans;
    }
};