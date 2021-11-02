class Solution {
   public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> t = words;
        int v[26] = {0};
        for (int i = 0; i < 26; i++)
            v[order[i] - 'a'] = i;
        sort(t.begin(), t.end(), [&](const string& a, const string& b) {
            int l1 = a.size(), l2 = b.size();
            int l3 = min(l1, l2);
            for (int i = 0; i < l3; i++) {
                if (v[a[i] - 'a'] < v[b[i] - 'a'])
                    return true;
                else if (v[a[i] - 'a'] > v[b[i] - 'a'])
                    return false;
            }
            return l1 < l2;
        });
        int l = words.size();
        for (int i = 0; i < l; i++) {
            if (words[i] != t[i])
                return false;
        }
        return true;
    }
};