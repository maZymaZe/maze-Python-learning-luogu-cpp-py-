class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int c[26] = {0}, mch = 0, a[26] = {0}, ls = s.size(), lp = p.size();
        if (lp > ls)
            return ans;
        for (int i = 0; i < lp; i++)
            c[p[i] - 'a']++;
        for (int i = 0; i < lp; i++)
            a[s[i] - 'a']++;
        for (int i = 0; i < 26; i++)
            if (c[i] == a[i])
                mch++;
        if (mch == 26)
            ans.push_back(0);
        for (int i = lp; i < ls; i++) {
            if (a[s[i - lp] - 'a'] == c[s[i - lp] - 'a'])
                mch--;
            else if (a[s[i - lp] - 'a'] == c[s[i - lp] - 'a'] + 1)
                mch++;
            a[s[i - lp] - 'a']--;
            if (a[s[i] - 'a'] == c[s[i] - 'a'])
                mch--;
            else if (a[s[i] - 'a'] == c[s[i] - 'a'] - 1)
                mch++;
            a[s[i] - 'a']++;
            if (mch == 26)
                ans.push_back(i - lp + 1);
        }
        return ans;
    }
};