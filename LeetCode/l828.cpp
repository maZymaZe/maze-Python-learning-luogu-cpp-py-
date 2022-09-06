class Solution {
   public:
    int uniqueLetterString(string s) {
        vector<int> o;
        int l = s.size(), ans = 0;
        for (int i = 0; i < 26; i++) {
            int pre = -1;
            o.clear();
            o.push_back(-1);
            for (int j = 0; j < l; j++) {
                if (s[j] == i + 'A') {
                    o.push_back(j);
                    // ans += (j - pre) * (l - j);
                    // pre = j;
                }
            }
            o.push_back(l);
            int ll = o.size();
            for (int j = 1; j < ll - 1; j++) {
                ans += (o[j] - o[j - 1]) * (o[j + 1] - o[j]);
            }
        }
        return ans;
    }
};