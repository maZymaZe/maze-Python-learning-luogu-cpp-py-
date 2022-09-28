struct TRIE {
    bool val = 0;
    TRIE* child[26];
    TRIE* pa;
};
class Solution {
   public:
    vector<string> ret;
    int mx = 0;
    map<int, vector<string>> mp;
    TRIE* root;
    void insert(const string& x) {
        TRIE* p = root;
        for (const auto& i : x) {
            if (!p->child[i - 'a']) {
                p->child[i - 'a'] = new TRIE();
            }
            p->child[i - 'a']->pa = p;
            p = p->child[i - 'a'];
        }
        p->val = 1;
    }
    void dfs(vector<string>& tmp, vector<string>& s, vector<TRIE*>& nd) {
        int m = tmp.size(), n = s[0].size();
        if (n * n <= mx)
            return;
        if (m >= n)
            return;
        for (int i = 0; i < s.size(); i++) {
            bool f1 = 1, f2 = 1;
            for (int j = 0; j < n; j++) {
                if (!nd[j]->child[s[i][j] - 'a']) {
                    f1 = f2 = 0;
                    break;
                }
                if (!nd[j]->child[s[i][j] - 'a']->val)
                    f2 = 0;
            }
            if (f1) {
                for (int j = 0; j < n; j++) {
                    nd[j] = nd[j]->child[s[i][j] - 'a'];
                }
                tmp.push_back(s[i]);
                if (f2) {
                    if ((m + 1) * n > mx) {
                        mx = (m + 1) * n;
                        ret = tmp;
                    }
                }
                dfs(tmp, s, nd);
                for (int j = 0; j < n; j++)
                    nd[j] = nd[j]->pa;
                tmp.pop_back();
            }
        }
    }
    vector<string> maxRectangle(vector<string>& words) {
        root = new TRIE();
        for (auto& x : words) {
            mp[x.size()].push_back(x);
            insert(x);
        }
        for (auto p = mp.rbegin(); p != mp.rend(); p++) {
            vector<string> tmp;
            vector<TRIE*> nd(p->first, root);
            dfs(tmp, p->second, nd);
        }
        return ret;
    }
};