#include <cstring>
#include <string>
#include <vector>
using namespace std;
string beginWord("hit");
string endWord("cog");
vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

int cnt = 0;
vector<int> h(1000);
struct edge {
    int u, v, nx;
};
vector<edge> e;
struct qq {
    int now, pre, s;
};
void add(int r, int t) {
    cnt++;
      e.push_back({r,t,h[r]});
    h[r] = cnt;
}

int main() {
    cnt = 0;
    int step = -1;
    int vis[1000] = {0};
    vector<vector<string>> ans;
    vector<qq> q;
    q.clear();
    e.clear();
    h.clear();
    e.push_back({0, 0, 0});
    memset(vis, 0, sizeof(vis));
    int bb = -1, ee = -1;
    for (int i = 0; i < wordList.size(); i++) {
        if (wordList[i] == beginWord)
            bb = i;
        if (wordList[i] == endWord)
            ee = i;
    }
    if (bb == -1)
        wordList.push_back(beginWord), bb = wordList.size() - 1;
    if (bb == -1 || ee == -1);
       // return ans;
    for (int a = 0; a < wordList.size(); a++) {
        for (int b = 0; b < a; b++) {
            int c = 0;
            for (int i = 0; i < wordList[a].size(); i++) {
                if (wordList[a][i] != wordList[b][i])
                    c++;
            }
            if (c == 1) {
                add(a, b);
                add(b, a);
            }
        }
    }
    int head = 1, tail = 1;
    q.push_back({0, 0, 0});
    q.push_back({bb, 0, 1});

    while (head <= tail) {
        if (q[head].s >= step && step != -1)
            break;
        for (int i = h[q[head].now]; i; i = e[i].nx) {
            if (vis[e[i].v] == 0 || e[i].v == ee) {
                tail++;
                vis[e[i].v] = 1;
                q.push_back({e[i].v, head, q[head].s + 1});
                if (q[tail].now == ee) {
                    if (step == -1)
                        step = q[tail].s;
                    vector<int> res;
                    int re = tail;
                    while (re) {
                        res.push_back(q[re].now);
                        re = q[re].pre;
                    }
                    vector<string> tmp;
                    for (int j = res.size() - 1; j >= 0; j--) {
                        tmp.push_back(wordList[res[j]]);
                    }
                    ans.push_back(tmp);
                }
            }
        }
        head++;
    }

    return 0;
}