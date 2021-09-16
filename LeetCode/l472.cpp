struct NODE {
    NODE* nx[26];
    bool ed;
};
class Solution {
   public:
    NODE* root;
    void ins(string& x) {
        int l = x.size();
        auto p = root;
        for (int i = 0; i < l; i++) {
            if (!p->nx[x[i] - 'a']) {
                p->nx[x[i] - 'a'] = new NODE();
            }
            p = p->nx[x[i] - 'a'];
        }
        p->ed = 1;
    }
    bool sch(const string& x, int s, int c) {
        if (s >= x.size())
            return c > 1;
        auto p = root;
        for (int i = s; i < x.size(); i++) {
            if (!p->nx[x[i] - 'a']) {
                return false;
            }
            if (p->nx[x[i] - 'a']->ed && sch(x, i + 1, c + 1))
                return true;
            p = p->nx[x[i] - 'a'];
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new NODE();
        vector<string> ans;
        sort(words.begin(), words.end(),
             [](auto& a, auto& b) { return a.size() < b.size(); });
        for (auto& w : words) {
            if (w.size() == 0)
                continue;
            if (sch(w, 0, 0))
                ans.push_back(w);
            else
                ins(w);
        }
        return ans;
    }
};