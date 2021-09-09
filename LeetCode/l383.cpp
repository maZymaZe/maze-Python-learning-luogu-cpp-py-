class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        int c[26] = {0};
        for (auto x : ransomNote)
            c[x - 'a']++;
        for (auto x : magazine)
            c[x - 'a']--;
        for (int i = 0; i < 26; i++)
            if (c[i] > 0)
                return false;
        return true;
    }
};