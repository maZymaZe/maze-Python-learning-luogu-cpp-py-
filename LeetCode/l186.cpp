class Solution {
   public:
    void reverseWords(vector<char>& s) {
        int l = s.size();
        reverse(s.begin(), s.end());
        int op = 0;
        for (int i = 0; i < l; i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + op, s.begin() + i);
                op = i + 1;
            }
        }
        reverse(s.begin() + op, s.end());
    }
};