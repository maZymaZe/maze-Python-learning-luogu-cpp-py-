struct edge {
    int v, nx;
};
struct node {
    int pos, stp;
};
class Solution {
   public:
    vector<int> h;
    vector<edge> v;
    vector<int> vis;
    queue<node> q;
    bool ck(const string& a, const string& b) {
        bool f = true;
        int l = a.size();
        for (int i = 0; i < l; i++) {
            if (a[i] != b[i]) {
                if (f)
                    f = false;
                else
                    return false;
            }
        }
        return true;
    }
    void adde(int a, int b) {
        v.push_back({b, h[a]});
        h[a] = v.size() - 1;
    }
    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {
        int mp[30][30] = {0};
        v.push_back({0, 0});
        if (beginWord == endWord)
            return 0;
        int l = wordList.size();
        h.resize(l + 1);
        vis.resize(l + 1);
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                if (ck(wordList[i], wordList[j])) {
                    adde(i + 1, j + 1);
                    adde(j + 1, i + 1);
                }
            }
        }
        for (int i = 0; i < l; i++) {
            if (ck(wordList[i], beginWord))
                q.push({i + 1, 1}), vis[i + 1] = 1;
        }
        while (!q.empty()) {
            node t = q.front();
            if (wordList[t.pos - 1] == endWord)
                return t.stp + 1;
            q.pop();
            for (int i = h[t.pos]; i; i = v[i].nx) {
                if (!vis[v[i].v]) {
                    q.push({v[i].v, t.stp + 1});
                    if (wordList[v[i].v - 1] == endWord)
                        return t.stp + 2;
                    vis[v[i].v] = 1;
                }
            }
        }
        return 0;
    }
};