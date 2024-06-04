#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> e;
    int n, ss;
    vector<int> ans;
    int dfs(int x, int f, int tot) {
        int r = 0;
        if (tot % ss == 0)
            r++;
        int sz = e[x].size();
        for (int i = 0; i < sz; i += 2) {
            if (e[x][i] != f) {
                r += dfs(e[x][i], x, tot + e[x][i + 1]);
            }
        }
        return r;
    }
    void dojob(int x) {
        int cnt = 0;
        int sz = e[x].size();
        for (int i = 0; i < sz; i += 2) {
            int t = dfs(e[x][i], x, e[x][i + 1]);
            ans[x] += cnt * t;
            cnt += t;
        }
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges,
                                               int signalSpeed) {
        n = edges.size() + 1;
        ss = signalSpeed;
        e.resize(n);
        ans.resize(n);
        for (const auto& edge : edges) {
            e[edge[0]].push_back(edge[1]);
            e[edge[0]].push_back(edge[2]);
            e[edge[1]].push_back(edge[0]);
            e[edge[1]].push_back(edge[2]);
        }
        for (int i = 0; i < n; i++) {
            dojob(i);
        }
        return ans;
    }
};
int main() {
    vector<int> e1{0, 1, 1}, e2{1, 2, 3};
    vector<vector<int>> e{e1, e2};
    Solution().countPairsOfConnectableServers(e, 1);
}