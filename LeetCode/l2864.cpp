class Solution {
   public:
    string maximumOddBinaryNumber(string s) {
        int c0 = 0;
        for (char c : s)
            c0 += (c == '0');
        return string(s.size() - c0 - 1, '1') + string(c0, '0') + '1';
    }
};