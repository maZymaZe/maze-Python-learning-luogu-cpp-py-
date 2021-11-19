class Solution {
   public:
    int n, f[300] = {0}, c[300] = {0};
    int ff(int x) { return f[x] == x ? x : f[x] = ff(f[x]); }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        for (int i = 0; i < n; i++)
            f[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    f[ff(i)] = ff(j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!c[ff(i)])
                ans++, c[ff(i)] = 1;
        }
        return ans;
    }
};