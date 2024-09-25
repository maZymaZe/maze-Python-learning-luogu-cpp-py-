struct TRIENODE {
    int NX[26] = {0};
    bool valid = false;
};
class Solution {
   public:
    vector<TRIENODE> v;
    int tv = 0;
    int find2(string x) {
        int p = 0, l = x.size();
        for (int i = 0; i < l - 1; i++) {
            p = v[p].NX[x[i] - 'a'];
        }
        return p;
    }
    void insert(const string& x) {
        int p = 0;
        for (char c : x) {
            if (v[p].NX[c - 'a'] == 0) {
                ++tv;
                v.push_back(TRIENODE());
                v[p].NX[c - 'a'] = tv;
            }
            p = v[p].NX[c - 'a'];
        }
        v[p].valid = true;
    }
    long long distinctNames(vector<string>& ideas) {
        vector<int> cnt(26);
        v.resize(1);
        tv = 0;
        int l = ideas.size();
        for (int i = 0; i < l; i++) {
            string t = ideas[i];
            cnt[t[0] - 'a']++;
            reverse(t.begin(), t.end());
            insert(t);
        }
        vector<vector<int>> cnt2(26, vector<int>(26, 0));
        for (int i = 0; i < l; i++) {
            int fr = ideas[i].front() - 'a';
            string t = ideas[i];
            reverse(t.begin(), t.end());
            int x = find2(t);
            for (int j = 0; j < 26; j++) {
                if (v[x].NX[j] != 0 && v[v[x].NX[j]].valid) {
                    cnt2[j][fr]++;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < l; i++) {
            int ok = l;
            int fr = ideas[i].front() - 'a';
            string t = ideas[i];
            reverse(t.begin(), t.end());
            int x = find2(t);
            for (int j = 0; j < 26; j++) {
                if (v[x].NX[j] != 0 && v[v[x].NX[j]].valid) {
                    ok -= cnt[j];
                } else
                    ok -= cnt2[fr][j];
            }
            ans += ok;
        }
        return ans;
    }
};