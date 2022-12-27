class Solution {
   public:
    int minimumMoves(string s) {
        int l = s.length(), p = 0, a = 0;
        while (p < l) {
            if (s[p] == 'X')
                a++, p += 3;
            else
                p++;
        }
        return a;
    }
};