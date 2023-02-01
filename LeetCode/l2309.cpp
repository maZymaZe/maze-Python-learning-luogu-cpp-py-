class Solution {
   public:
    string greatestLetter(string s) {
        int c[27] = {0};
        for (char d : s) {
            if (d >= 'a' && d <= 'z') {
                c[d - 'a'] |= 1;
            }
            if (d >= 'A' && d <= 'Z') {
                c[d - 'A'] |= 2;
            }
        }
        for (int i = 25; i >= 0; i--)
            if (c[i] == 3)
                return string(1, i + 'A');
        return "";
    }
};