class Solution {
   public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        for (int i = 0; i < m; ++i) {
            deque<int> q;
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    // 遇到障碍物，清空队列
                    q.clear();
                } else if (box[i][j] == '#') {
                    if (!q.empty()) {
                        // 如果队列不为空，石头就会下落
                        int pos = q.front();
                        q.pop_front();
                        box[i][pos] = '#';
                        box[i][j] = '.';
                        // 由于下落，石头变为空位，也需要加入队列
                        q.push_back(j);
                    }
                } else {
                    // 将空位加入队列
                    q.push_back(j);
                }
            }
        }

        // 将矩阵顺时针旋转 90 度放入答案
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        return ans;
    }
};
