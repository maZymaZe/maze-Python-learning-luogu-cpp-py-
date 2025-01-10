class Solution {
   public:
    long long validSubstringCount(string word1, string word2) {
        long long ans = 0;
        int c1[26] = {0}, c2[26] = {0}, m = 0, l1 = word1.size(), r = 0;
        for (char c : word2) {
            c2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++)
            if (c1[i] == c2[i])
                m++;
        for (int i = 0; i < l1; i++) {
            c1[word1[i] - 'a']++;
            if (c1[word1[i] - 'a'] == c2[word1[i] - 'a'])
                m++;
            while (m == 26) {
                c1[word1[r] - 'a']--;
                if (c1[word1[r] - 'a'] == c2[word1[r] - 'a'] - 1)
                    m--;
                r++;
            }
            ans += r;
        }
        return ans;
    }
};