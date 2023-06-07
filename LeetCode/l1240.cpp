class Solution {
   public:
    int ans;
    int tilingRectangle(int n, int m) {
        ans = max(n, m);
        vector<vector<bool>> rect(n, vector<bool>(m, false));
        dfs(0, 0, rect, 0);
        return ans;
    }

    void dfs(int x, int y, vector<vector<bool>>& rect, int cnt) {
        int n = rect.size(), m = rect[0].size();
        if (cnt >= ans) {
            return;
        }
        if (x >= n) {
            ans = cnt;
            return;
        }
        /* 检测下一行 */
        if (y >= m) {
            dfs(x + 1, 0, rect, cnt);
            return;
        }
        /* 如当前已经被覆盖，则直接尝试下一个位置 */
        if (rect[x][y]) {
            dfs(x, y + 1, rect, cnt);
            return;
        }

        for (int k = min(n - x, m - y); k >= 1 && isAvailable(rect, x, y, k);
             k--) {
            /* 将长度为 k 的正方形区域标记覆盖 */
            fillUp(rect, x, y, k, true);
            /* 跳过 k 个位置开始检测 */
            dfs(x, y + k, rect, cnt + 1);
            fillUp(rect, x, y, k, false);
        }
    }

    bool isAvailable(vector<vector<bool>>& rect, int x, int y, int k) {
        for (int i = 0; i < k; i++) {
            if (accumulate(rect[x + i].begin() + y, rect[x + i].begin() + y + k,
                           false, bit_or())) {
                return false;
            }
        }
        return true;
    }

    void fillUp(vector<vector<bool>>& rect, int x, int y, int k, bool val) {
        for (int i = 0; i < k; i++) {
            fill(rect[x + i].begin() + y, rect[x + i].begin() + y + k, val);
        }
    }
};
