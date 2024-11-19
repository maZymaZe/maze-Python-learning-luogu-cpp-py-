class Solution {
   public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<int>> eg(n);
        vector<int> ans;
        for (int i = 0; i < n - 1; i++)
            eg[i].push_back(i + 1);
        for (auto& qu : queries) {
            eg[qu[0]].push_back(qu[1]);
            vector<int> vis(n);
            vis[0] = 1;
            queue<int> p, v;
            p.push(0), v.push(0);
            while (!p.empty()) {
                int tp = p.front(), tv = v.front();
                p.pop();
                v.pop();
                for (int i : eg[tp]) {
                    if (!vis[i]) {
                        if (i == n - 1)
                            ans.push_back(tv + 1);
                        p.push(i), v.push(tv + 1);
                        vis[i] = 1;
                    }
                }
            }
        }
        return ans;
    }
};