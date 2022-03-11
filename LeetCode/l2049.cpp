#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> v;
    int l;
    long long mx = -1, rs = 0;
    int dfs(int rt) {
        int le = v[rt].size();
        long long ans = 1, tot = 1;
        for (int i = 0; i < le; i++) {
            int r = dfs(v[rt][i]);
            ans *= r, tot += r;
        }
        ans *= max(1, (int)(l - tot));
        if (ans > mx) {
            mx = ans;
            rs = 1;
        } else if (ans == mx)
            rs++;
        return tot;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        l = parents.size();
        v.resize(l);
        for (int i = 0; i < l; i++) {
            if (parents[i] != -1)
                v[parents[i]].push_back(i);
        }
        dfs(0);
        return rs;
    }
};
int main() {
    vector<int> a{-1, 2, 0};
    Solution().countHighestScoreNodes(a);
}