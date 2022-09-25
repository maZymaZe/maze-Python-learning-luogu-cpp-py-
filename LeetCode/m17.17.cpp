struct TRIE {
    int vis[26] = {0};
    int fail, exist;
    TRIE() {
        memset(vis, 0, sizeof(vis));
        fail = 0, exist = 0;
    }
};
class Solution {
   public:
    vector<TRIE> tr;
    void add(const string& x, int id) {
        if (x.size() == 0)
            return;
        int p = 0, l = x.size();
        for (int i = 0; i < l; i++) {
            if (!tr[p].vis[x[i] - 'a']) {
                tr[p].vis[x[i] - 'a'] = tr.size();
                tr.push_back(TRIE());
            }
            p = tr[p].vis[x[i] - 'a'];
        }
        tr[p].exist = id;
    }
    void getfail() {
        queue<int> q;
        tr[0].fail = 0;
        for (int i = 0; i < 26; i++) {
            if (tr[0].vis[i]) {
                tr[tr[0].vis[i]].fail = 0;
                q.push(tr[0].vis[i]);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (tr[u].vis[i]) {
                    tr[tr[u].vis[i]].fail = tr[tr[u].fail].vis[i];
                    q.push(tr[u].vis[i]);
                } else {
                    tr[u].vis[i] = tr[tr[u].fail].vis[i];
                }
            }
        }
    }
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        int len = smalls.size();
        tr.resize(1);
        for (int i = 0; i < len; i++) {
            add(smalls[i], i + 1);
        }
        vector<vector<int>> ans(len);
        int l = big.size();
        getfail();
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = big[i] - 'a';
            while (p && !tr[p].vis[c])
                p = tr[p].fail;
            p = tr[p].vis[c];
            int k = p;
            do {
                if (tr[k].exist > 0) {
                    ans[tr[k].exist - 1].push_back(
                        i + 1 - smalls[tr[k].exist - 1].size());
                }
                k = tr[k].fail;
            } while (k);
        }
        return ans;
    }
};