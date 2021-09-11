class Solution {
   public:
    bool checkValidString(string s) {
        vector<int> vis[2];
        int l = s.length();
        vis[0].resize(l + 2), vis[1].resize(l + 2);
        vis[1][0] = 1;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j <= l; j++) {
                int a = (i & 1), b = ((i & 1) ^ 1);
                vis[a][j] = 0;
                if (s[i] == '(') {
                    if (j > 0)
                        vis[a][j] = vis[b][j - 1];
                } else if (s[i] == ')') {
                    if (j + 1 <= l)
                        vis[a][j] = vis[b][j + 1];
                } else {
                    vis[a][j] |= vis[b][j];
                    if (j > 0)
                        vis[a][j] |= vis[b][j - 1];
                    if (j + 1 <= l)
                        vis[a][j] |= vis[b][j + 1];
                }
            }
        }
        return vis[(l - 1) & 1][0];
    }
};