class Solution {
   public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        queue<int> qx, qy;
        int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1},
            dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 0) {
                    qx.push(i), qy.push(j);
                    int cnt = 1;
                    land[i][j] = 1;
                    while (!qx.empty()) {
                        int x = qx.front(), y = qy.front();
                        qx.pop(), qy.pop();
                        for (int k = 0; k < 8; k++) {
                            int nx = x + dx[k], ny = y + dy[k];
                            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                                land[nx][ny] == 0) {
                                land[nx][ny] = 1;
                                qx.push(nx), qy.push(ny);
                                cnt++;
                            }
                        }
                    }
                    ans.push_back(cnt);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};