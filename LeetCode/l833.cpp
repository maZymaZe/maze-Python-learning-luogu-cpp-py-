class Solution {
   public:
    string findReplaceString(string s,
                             vector<int>& indices,
                             vector<string>& sources,
                             vector<string>& targets) {
        int k = indices.size(), l = s.size();
        vector<int> b(k);
        map<int, int> mp;

        for (int i = 0; i < k; i++) {
            mp[indices[i]] = i;
        }
        int p = 0;
        string ans;
        while (p < l) {
            if (!mp.count(p)) {
                ans += s[p];
                p++;
            } else {
                int x = mp[p];
                if (s.substr(p, sources[x].size()) == sources[x]) {
                    ans += targets[x];
                    p += sources[x].size();
                } else {
                    ans += s[p];
                    p++;
                }
            }
        }
        return ans;
    }
};