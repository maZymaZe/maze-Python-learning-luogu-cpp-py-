class Solution {
   public:
    string addSpaces(string s, vector<int>& spaces) {
        int l = s.size(), lp = spaces.size(), p = 0;
        string ans;
        for (int i = 0; i < l; i++) {
            if (p < lp && i == spaces[p])
                ans += ' ', p++;
            ans += s[i];
        }
        return ans;
    }
};