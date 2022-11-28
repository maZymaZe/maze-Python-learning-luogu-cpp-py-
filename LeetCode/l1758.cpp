class Solution {
   public:
    int minOperations(string s) {
        int c1 = 0, c2 = 0, l = s.size();
        for (int i = 0; i < l; i++) {
            if (s[i] - '0' == (i & 1))
                c1++;
            else
                c2++;
        }
        return min(c1, c2);
    }
};