class Solution {
   public:
    string reverseLeftWords(string s, int n) {
        int l = s.size();
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + (l - n));
        reverse(s.begin() + (l - n), s.end());
        return s;
    }
};