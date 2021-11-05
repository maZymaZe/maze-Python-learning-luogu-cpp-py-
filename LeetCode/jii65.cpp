struct TRIE {
    int nx[26];
    bool ex;
};
class Solution {
   public:
    int root = 1;
    vector<TRIE> tr;
    vector<int> stp;
    void TRIEINIT() {
        tr.resize(2);
        root = 1;
    }
    void insert(const string& x, int t) {
        int p = root, i = 0, l = x.size();
        while (i < l) {
            if (tr[p].nx[x[i] - 'a']) {
                p = tr[p].nx[x[i] - 'a'];
                i++;
            } else {
                tr.push_back(TRIE());
                tr[p].nx[x[i] - 'a'] = tr.size() - 1;
                p = tr.size() - 1;
                i++;
            }
        }
        tr[p].ex = true;
        stp[t] = p;
    }
    int minimumLengthEncoding(vector<string>& words) {
        TRIEINIT();
        int l = words.size(), ans = 0;
        stp.resize(l);
        for (int i = 0; i < l; i++) {
            reverse(words[i].begin(), words[i].end());
            insert(words[i], i);
        }
        unordered_set<int> s;
        for (int i = 0; i < l; i++) {
            int p = stp[i], f = 1;
            if (s.count(p))
                continue;
            s.insert(p);
            for (int j = 0; j < 26; j++) {
                if (tr[p].nx[j]) {
                    f = 0;
                    break;
                }
            }
            ans += f * (words[i].size() + 1);
        }
        return ans;
    }
};