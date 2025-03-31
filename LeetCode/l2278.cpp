class Solution {
   public:
    int percentageLetter(string s, char letter) {
        int x = 0;
        for (char c : s)
            if (c == letter)
                x++;
        return 100 * x / s.size();
    }
};