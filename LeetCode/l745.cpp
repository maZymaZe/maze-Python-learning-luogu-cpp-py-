struct TRND {
    TRND* nx[27];
    int ans;
};
class WordFilter {
   public:
    TRND* trie;
    int tp = 1;
    void ins(string x, int k) {
        int l = x.length();
        x = x + '{' + x;
        int t = x.length();
        for (int i = 0; i < l; i++) {
            inssp(x, i, t, k);
        }
    }
    void inssp(const string& x, int bg, int ed, int k) {
        TRND* p = trie;
        for (int i = bg; i < ed; i++) {
            char c = x[i];
            if (!p->nx[c - 'a']) {
                p->nx[c - 'a'] = new TRND();
            }
            p = p->nx[c - 'a'];
            p->ans = k;
        }
    }
    int fd(string x) {
        TRND* p = trie;
        for (auto c : x) {
            if (!p->nx[c - 'a']) {
                return 0;
            }
            p = p->nx[c - 'a'];
        }
        return p->ans;
    }
    WordFilter(vector<string>& words) {
        trie = new TRND();
        int l = words.size();
        for (int i = 0; i < l; i++) {
            ins(words[i], i + 1);
        }
    }

    int f(string prefix, string suffix) {
        return fd((suffix + '{' + prefix)) - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */