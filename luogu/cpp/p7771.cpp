#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
const int NMAX = 1e5 + 10;
int n, tx, ty, m;
vector<int> nx[NMAX];
stack<int> st;
int d[NMAX][2];
int del[NMAX];
void dfs(int x) {
    int l = nx[x].size();
    for (int i = del[x]; i < l; i = del[x]) {
        del[x] = i + 1;
        dfs(nx[x][i]);
    }
    st.push(x);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &tx, &ty);
        nx[tx].push_back(ty);
        d[tx][1]++, d[ty][0]++;
    }
    for (int i = 1; i <= n; i++)
        sort(nx[i].begin(), nx[i].end());
    int S = 1, cnt[2] = {0};
    bool f = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i][0] != d[i][1])
            f = 0;
        if (d[i][1] - d[i][0] == 1)
            cnt[1]++, S = i;
        if (d[i][0] - d[i][1] == 1)
            cnt[0]++;
    }
    if ((!f) && !(cnt[0] == cnt[1] && cnt[0] == 1)) {
        printf("No");
        return 0;
    }
    dfs(S);
    while (!st.empty())
        printf("%d ", st.top()), st.pop();
    return 0;
}