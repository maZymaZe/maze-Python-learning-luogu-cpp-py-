class Solution {
   public:
    int lengthOfLastWord(string s) {
        int l = s.size();
        while (l && s[l - 1] == ' ')
            l--;
        for (int i = l - 1; i >= 0; i--) {
            if (s[i] == ' ')
                return l - i - 1;
        }
        return l;
    }
};