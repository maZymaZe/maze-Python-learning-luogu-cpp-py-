#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int SUM_OF_PATTERN_LENGTH = 1e5 + 50;
const int LETTER_SIZE = 30;
const int ANS_SIZE = 1e5 + 50;
struct Trie {
    int vis[LETTER_SIZE], fail, exist;
};

struct Result {
    int pos, num;
    bool operator<(const Result& x) {
        return num > x.num || (num == x.num && pos < x.pos);
    }
};
int cnt[] = {0};
void Clean(vector<Trie>& trie, const int x) {
    memset(trie[x].vis, 0, sizeof(trie[x].vis));
    trie[x].exist = trie[x].fail = 0;
}
void TrieInsert(vector<Trie>& trie, const string& s, int Num) {//注意不要让Num==0，从1开始
    int p = 0, l = s.size();
    for (int i = 0; i < l; i++) {
        if (!trie[p].vis[s[i] - 'a']) {
            trie[p].vis[s[i] - 'a'] = ++cnt[0];
            Clean(trie, cnt[0]);
        }
        p = trie[p].vis[s[i] - 'a'];
    }
    trie[p].exist = Num;
}
void GetFail(vector<Trie>& trie) {
    queue<int> q;
    trie[0].fail = 0;
    for (int i = 0; i < 26; i++) {
        if (trie[0].vis[i]) {
            trie[trie[0].vis[i]].fail = 0;
            q.push(trie[0].vis[i]);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (trie[u].vis[i]) {
                trie[trie[u].vis[i]].fail = trie[trie[u].fail].vis[i];
                q.push(trie[u].vis[i]);
            } else
                trie[u].vis[i] = trie[trie[u].fail].vis[i];
        }
    }
}
void AC_Query(vector<Trie>& trie, const string& s, vector<Result>& ans) {
    int l = s.size();
    int p = 0;
    for (int i = 0; i < l; i++) {
        p = trie[p].vis[s[i] - 'a'];
        for (int t = p; t; t = trie[t].fail) {
            ans[trie[t].exist].num++;
        }
    }
}
vector<Trie> trie(SUM_OF_PATTERN_LENGTH);
vector<Result> ans(ANS_SIZE);
vector<string> s(ANS_SIZE);
string tt;
int main() {
    int n = 0;
    cin >> n;
    while (n) {
        cnt[0] = 0;
        Clean(trie, 0);
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            ans[i].num = 0;
            ans[i].pos = i;
            TrieInsert(trie, s[i], i);
        }
        GetFail(trie);
        cin >> tt;
        AC_Query(trie, tt, ans);
        sort(&ans[1], (&ans[1]) + n);
        cout << ans[1].num << endl << s[ans[1].pos] << endl;
        for (int i = 2; i < n; i++) {
            if (ans[i].num == ans[i - 1].num) {
                cout << s[ans[i].pos] << endl;
            } else
                break;
        }
        cin >> n;
    }
    return 0;
}