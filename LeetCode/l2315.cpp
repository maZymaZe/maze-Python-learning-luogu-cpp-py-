class Solution {
   public:
    int countAsterisks(string s) {
        int ans = 0, p = 1;
        for (char c : s) {
            if (c == '|')
                p ^= 1;
            else if (c == '*')
                ans += p;
        }
        return ans;
    }
};