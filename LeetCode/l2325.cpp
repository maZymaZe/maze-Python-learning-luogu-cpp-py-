class Solution {
   public:
    string decodeMessage(string key, string message) {
        int v[26] = {0}, p = 0, m[26] = {0};
        for (char c : key) {
            if (c < 'a' || c > 'z')
                continue;
            if (!v[c - 'a']) {
                v[c - 'a'] = 1;
                m[c - 'a'] = p++;
            }
        }
        string s;
        for (char c : message) {
            if (c == ' ')
                s += ' ';
            else
                s += (char)(m[c - 'a'] + 'a');
        }
        return s;
    }
};