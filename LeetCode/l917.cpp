class Solution {
   public:
    bool ck(char x) { return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'); }
    string reverseOnlyLetters(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !ck(s[l]))
                l++;
            while (l < r && !ck(s[r]))
                r--;
            if (l < r) {
                swap(s[l], s[r]);
                l++, r--;
            }
        }
        return s;
    }
};