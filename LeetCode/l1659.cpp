class Solution {
   public:
    vector<int> l1, l2;
    int dp[729][7][7][7], vis[729][7][7][7];
    int mm, nn;
    int lv[729], llv[729][729], ci[729], ce[729];
    void fillline(int x, vector<int>& li) {
        for (int i = 0; i < mm; i++) {
            li[i] = x % 3;
            x /= 3;
        }
    }
    // int pressline(vector<int>& li) {
    //     int x = 0;
    //     for (int i = mm - 1; i >= 0; i--) {
    //         x = x * 3 + li[i];
    //     }
    //     return x;
    // }
    int dfs(int pre, int no, int ic, int ec) {
        if (no == nn)
            return 0;
        if (vis[pre][no][ic][ec])
            return dp[pre][no][ic][ec];
        vis[pre][no][ic][ec] = 1;
        int mmk = -60000;
        int sz = pow(3, mm);
        for (int i = 0; i < sz; i++) {
            if (ci[i] > ic)
                continue;
            if (ce[i] > ec)
                continue;
            int mk = lv[i] + llv[pre][i];
            mk += dfs(i, no + 1, ic - ci[i], ec - ce[i]);
            mmk = max(mk, mmk);
        }
        return dp[pre][no][ic][ec] = mmk;
    }
    int getMaxGridHappiness(int m,
                            int n,
                            int introvertsCount,
                            int extrovertsCount) {
        mm = n, nn = m;
        l1.resize(mm), l2.resize(mm);
        int sz = pow(3, mm);
        for (int i = 0; i < sz; i++) {
            fillline(i, l2);
            int mk = 0;
            for (int j = 0; j < mm; j++) {
                if (l2[j] == 1) {
                    mk += 120;
                    if (j > 0 && (l2[j - 1])) {
                        mk -= 30;
                    }
                    if (j < mm - 1 && (l2[j + 1])) {
                        mk -= 30;
                    }
                } else if (l2[j] == 2) {
                    mk += 40;
                    if (j > 0 && (l2[j - 1])) {
                        mk += 20;
                    }
                    if (j < mm - 1 && (l2[j + 1])) {
                        mk += 20;
                    }
                }
            }
            lv[i] = mk;
            for (int j = 0; j < mm; j++) {
                if (l2[j] == 1)
                    ci[i]++;
                else if (l2[j] == 2)
                    ce[i]++;
            }
        }
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                fillline(i, l1);
                fillline(j, l2);
                for (int k = 0; k < mm; k++) {
                    if (l1[k] && l2[k]) {
                        if (l1[k] == 1 && l2[k] == 1) {
                            llv[i][j] -= 60;
                        } else if (l1[k] == 2 && l2[k] == 2) {
                            llv[i][j] += 40;
                        } else {
                            llv[i][j] -= 10;
                        }
                    }
                }
            }
        }
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }
};