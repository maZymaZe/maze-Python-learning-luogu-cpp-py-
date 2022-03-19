class Solution {
   private:
    // 递归函数
    // curr 表示当前的位置
    // steps表示步数，默认从0开始
    // lastBack表示上一步是否是back，避免连续两次的back
    void dfs(bool* visited,
             int a,
             int b,
             int x,
             int& res,
             int curr,
             int steps,
             bool lastBack) {
        if (res == -1 && curr >= 0 && curr <= 6000) {
            if (curr != x) {
                // cout << curr << endl;
                // 要过滤掉已经遍历过的情况
                // 先前进
                if (!visited[curr + a]) {
                    visited[curr + a] = true;
                    dfs(visited, a, b, x, res, curr + a, steps + 1, false);
                }
                // 后后退
                if (!lastBack && (curr - b >= 0) && !visited[curr - b]) {
                    dfs(visited, a, b, x, res, curr - b, steps + 1, true);
                }
            } else {
                // 达到终点了，直接返回
                res = steps;
            }
        }
    }

   public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // unordered_set<int> visited;
        bool visited[8000];
        memset(visited, 0, sizeof(bool) * 8000);
        // 默认把forbidden插入已经遍历的里面表示不可达
        for (int f : forbidden) {
            // visited.insert(f);
            visited[f] = true;
        }

        // 默认-1表示不可达
        int res = -1;
        dfs(visited, a, b, x, res, 0, 0, false);
        return res;
    }
};