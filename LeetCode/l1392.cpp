class Solution {
   public:
    string longestPrefix(string s) {
        int l = s.size();
        vector<int> nx(l);
        nx[0] = -1;
        for (int i = 1; i < l; i++) {
            int j = nx[i - 1];
            while (j != -1 && s[j + 1] != s[i]) {
                j = nx[j];
            }
            if (s[j + 1] == s[i]) {
                nx[i] = j + 1;
            } else
                nx[i] = -1;
        }
        return s.substr(0, nx[l - 1] + 1);
    }
};