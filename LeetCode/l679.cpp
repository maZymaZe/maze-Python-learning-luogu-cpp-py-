class Solution {
   public:
    bool flag;
    int used[5], p, usedp[5];
    double nb[5];

    void dfs(int t, double res) {
        if (flag)
            return;
        if (t == 3 && fabs(res - 24) < 1e-6) {
            flag = true;
            return;
        }
        if (t < 3) {
            for (int i = 0; i < 3; i++) {
                if (!usedp[i]) {
                    usedp[i] = 1;
                    dfs(t + 1, res + nb[i]);
                    dfs(t + 1, res - nb[i]);
                    dfs(t + 1, nb[i] - res);
                    dfs(t + 1, res * nb[i]);
                    if (fabs(res) > 1e-6)
                        dfs(t + 1, 1.0 * nb[i] / res);
                    dfs(t + 1, res / nb[i]);
                    usedp[i] = 0;
                    if (flag)
                        return;
                }
            }
        }
    }
    bool judgePoint24(vector<int>& nums) {
        flag = false;
        for (int l = 0; l < 4; l++)
            for (int j = l + 1; j < 4; j++) {
                memset(used, 0, sizeof(used));
                used[l] = used[j] = 1;

                p = 1;
                for (int k = 0; k < 4; k++) {
                    if (!used[k])
                        nb[p++] = nums[k];
                }
                nb[0] = nums[l] + nums[j];
                for (int i = 0; i < 3; i++) {
                    memset(usedp, 0, sizeof(usedp));
                    usedp[i] = 1;
                    dfs(1, nb[i]);
                    if (flag)
                        return true;
                }
                nb[0] = nums[l] - nums[j];
                for (int i = 0; i < 3; i++) {
                    memset(usedp, 0, sizeof(usedp));
                    usedp[i] = 1;
                    dfs(1, nb[i]);
                    if (flag)
                        return true;
                }
                nb[0] = nums[j] - nums[l];
                for (int i = 0; i < 3; i++) {
                    memset(usedp, 0, sizeof(usedp));
                    usedp[i] = 1;
                    dfs(1, nb[i]);
                    if (flag)
                        return true;
                }
                nb[0] = nums[l] * nums[j];
                for (int i = 0; i < 3; i++) {
                    memset(usedp, 0, sizeof(usedp));
                    usedp[i] = 1;
                    dfs(1, nb[i]);
                    if (flag)
                        return true;
                }
                nb[0] = 1.0 * nums[l] / nums[j];
                for (int i = 0; i < 3; i++) {
                    memset(usedp, 0, sizeof(usedp));
                    usedp[i] = 1;
                    dfs(1, nb[i]);
                    if (flag)
                        return true;
                }
                nb[0] = 1.0 * nums[j] / nums[l];
                for (int i = 0; i < 3; i++) {
                    memset(usedp, 0, sizeof(usedp));
                    usedp[i] = 1;
                    dfs(1, nb[i]);
                    if (flag)
                        return true;
                }
            }
        return false;
    }
};