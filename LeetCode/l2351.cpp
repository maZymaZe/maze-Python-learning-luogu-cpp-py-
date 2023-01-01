class Solution {
   public:
    char repeatedCharacter(string s) {
        int a[300] = {0};
        for (auto c : s) {
            if (a[c])
                return c;
            a[c] = 1;
        }
        return 0;
    }
};