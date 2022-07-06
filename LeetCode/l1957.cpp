class Solution {
   public:
    string makeFancyString(string s) {
        string ans;
        int l = s.size();
        for (int i = 0; i < l; i++) {
            if (i - 2 >= 0 && s[i] == s[i - 1] && s[i - 1] == s[i - 2])
                continue;
            ans += s[i];
        }
        return ans;
    }
};