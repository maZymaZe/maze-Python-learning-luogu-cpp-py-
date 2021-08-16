class Solution {
   public:
    bool checkRecord(string s) {
        int l = s.size(), c = 0;
        for (int i = 0; i < l; i++)
            if (s[i] == 'A')
                c++;
        if (c >= 2)
            return false;
        for (int i = 0; i + 2 < l; i++) {
            if (s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L')
                return false;
        }
        return true;
    }
};