class Solution {
   public:
    string gen(string s, int idx, int offset) {
        s[idx] += offset;
        int l = s.size();
        for (int i = idx + 1; i < l; i++) {
            unordered_set<char> bc;
            for (int j = 1; j <= 2; j++) {
                if (i - j >= 0) {
                    bc.insert(s[i - j]);
                }
            }
            for (int j = 0; j < 3; j++) {
                if (!bc.count('a' + j)) {
                    s[i] = 'a' + j;
                    break;
                }
            }
        }
        return s;
    }
    string smallestBeautifulString(string s, int k) {
        int l = s.size();
        for (int i = l - 1; i >= 0; i--) {
            unordered_set<char> bc;
            for (int j = 1; j <= 2; j++) {
                if (i - j >= 0) {
                    bc.insert(s[i - j]);
                }
            }
            for (int j = 1; j <= 3; j++) {
                if (s[i] - 'a' + j + 1 <= k && !bc.count(s[i] + j)) {
                    return gen(s, i, j);
                }
            }
        }
        return "";
    }
};