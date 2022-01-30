class Solution {
   public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        s1 += ' ';
        s2 += ' ';
        int pre = 0, l = s1.length();
        map<string, int> mp;
        for (int i = 0; i < l; i++) {
            if (s1[i] == ' ') {
                mp[s1.substr(pre, i - pre)]++;
                pre = i + 1;
            }
        }
        l = s2.length();
        pre = 0;
        for (int i = 0; i < l; i++) {
            if (s2[i] == ' ') {
                mp[s2.substr(pre, i - pre)]++;
                pre = i + 1;
            }
        }
        vector<string> ans;
        l = s1.length();
        pre = 0;
        for (int i = 0; i < l; i++) {
            if (s1[i] == ' ') {
                if (mp[s1.substr(pre, i - pre)] == 1)
                    ans.push_back(s1.substr(pre, i - pre));
                pre = i + 1;
            }
        }
        l = s2.length();
        pre = 0;
        for (int i = 0; i < l; i++) {
            if (s2[i] == ' ') {
                if (mp[s2.substr(pre, i - pre)] == 1)
                    ans.push_back(s2.substr(pre, i - pre));
                pre = i + 1;
            }
        }
        return ans;
    }
};