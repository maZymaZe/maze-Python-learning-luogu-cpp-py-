class Solution {
   public:
    int maxRepOpt1(string text) {
        int l = text.length();
        int c[26] = {0};
        for (char x : text)
            c[x - 'a']++;
        vector<int> ch, ct;
        int nch = text[0], nct = 0;
        for (int i = 0; i < l; i++) {
            if (text[i] == nch)
                nct++;
            else {
                ch.push_back(nch), ct.push_back(nct);
                nch = text[i];
                nct = 1;
            }
        }
        ch.push_back(nch), ct.push_back(nct);
        int ll = ch.size(), ans = 0;
        for (int i = 0; i < ll; i++) {
            if (i > 0 && i + 1 < ll && ch[i - 1] == ch[i + 1] && ct[i] == 1) {
                ans =
                    max(ans, ct[i - 1] + ct[i + 1] +
                                 (c[ch[i - 1] - 'a'] > ct[i - 1] + ct[i + 1]));
            }
            ans = max(ans, ct[i] + (c[ch[i] - 'a'] > ct[i]));
        }
        return ans;
    }
};