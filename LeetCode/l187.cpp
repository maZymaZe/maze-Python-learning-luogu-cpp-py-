class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        int l = s.size();
        if (l < 10)
            return {};
        int c[300] = {0};
        c['A'] = 0, c['C'] = 1, c['G'] = 2, c['T'] = 3;
        c[0] = 'A', c[1] = 'C', c[2] = 'G', c[3] = 'T';
        int mp[1100000] = {0};
        int x = 0;
        for (int i = 0; i < 10; i++) {
            x = (x << 2) | c[s[i]];
        }
        mp[x]++;
        for (int i = 10; i < l; i++) {
            x -= (c[s[i - 10]] << 18);
            x <<= 2;
            x |= c[s[i]];
            mp[x]++;
        }
        vector<string> ans;
        for (int i = 0; i < 1049000; i++) {
            if (mp[i] > 1) {
                int t = i;
                string ss(10, ' ');
                for (int j = 9; j >= 0; j--) {
                    ss[j] = c[t & 3];
                    t >>= 2;
                }
                ans.push_back(ss);
            }
        }
        return ans;
    }
};