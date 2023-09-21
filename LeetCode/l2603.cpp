class Solution {
   public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<int> del(n), dg(n);
        vector<vector<int>> ee(n);
        for (auto& e : edges) {
            ee[e[0]].push_back(e[1]);
            ee[e[1]].push_back(e[0]);
            dg[e[0]]++, dg[e[1]]++;
        }
        vector<int> v1(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (dg[i] == 1 && coins[i] == 0) {
                q.push(i);
                del[i] = 1;
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i : ee[x]) {
                if (!del[i]) {
                    dg[i]--;
                    if (dg[i] == 1 && coins[i] == 0) {
                        q.push(i);
                        del[i] = 1;
                    }
                }
            }
        }
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n; i++) {
                if (dg[i] == 1 && !del[i]) {
                    q.push(i);
                    del[i] = 1;
                }
            }
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int i : ee[x]) {
                    if (!del[i]) {
                        dg[i]--;
                    }
                }
            }
        }
        int tot = 0;
        for (int i = 0; i < n; i++)
            if (!del[i])
                tot++;
        return max(0, tot * 2 - 2);
    }
};