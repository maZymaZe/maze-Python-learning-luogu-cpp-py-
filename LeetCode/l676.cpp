struct TRIE {
    int nx[26];
    bool ex;
};
class MagicDictionary {
   public:
    int root = 1;
    vector<TRIE> tr;
    void TRIEINIT() {
        tr.resize(2);
        root = 1;
    }
    void insert(const string& x) {
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
    }
    bool fulmch(int rt, const string& x) {
        int p = rt, l = x.size();
        for (int i = 0; i < l; i++) {
            if (tr[p].nx[x[i] - 'a']) {
                p = tr[p].nx[x[i] - 'a'];
            } else
                return false;
        }
        return tr[p].ex;
    }
    bool mch(const string& x) {
        int p = root, l = x.size();
        for (int i = 0; i < l; i++) {
            if (i == l - 1) {
                for (int j = 0; j < 26; j++) {
                    if (j == x[i] - 'a')
                        continue;
                    if (tr[p].nx[j] && tr[tr[p].nx[j]].ex)
                        return true;
                }
                break;
            }
            auto tt = x.substr(i + 1, l);
            for (int j = 0; j < 26; j++) {
                if (j == x[i] - 'a')
                    continue;
                if (tr[p].nx[j]) {
                    if (fulmch(tr[p].nx[j], tt))
                        return true;
                }
            }
            if (tr[p].nx[x[i] - 'a']) {
                p = tr[p].nx[x[i] - 'a'];
            } else
                return false;
        }
        return false;
    }
    MagicDictionary() { TRIEINIT(); }

    void buildDict(vector<string> dictionary) {
        for (const auto& x : dictionary)
            insert(x);
    }

    bool search(string searchWord) { return mch(searchWord); }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */