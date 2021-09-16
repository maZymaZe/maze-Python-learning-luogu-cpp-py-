class Solution {
   public:
    char firstUniqChar(string s) {
        int c[26] = {0};
        for (char i : s)
            c[i - 'a']++;
        for (char i : s)
            if (c[i - 'a'] == 1)
                return i;
        return ' ';
    }
};