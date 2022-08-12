class Solution {
   public:
    int v[60][60][2];
    int dp[60][60][2];
    int dfs(string& s, int l, int r, int x) {
        if (v[l][r][x])
            return dp[l][r][x];
        v[l][r][x] = 1;
        if (l == r)
            return dp[l][r][x] = ((s[l] - '0') == x);
        int ans = 0;
        for (int i = l + 1; i <= r - 1; i += 2) {
            if (s[i] == '|') {
                if (x == 0) {
                    ans += dfs(s, l, i - 1, 0) * dfs(s, i + 1, r, 0);
                } else {
                    ans += dfs(s, l, i - 1, 0) * dfs(s, i + 1, r, 1);
                    ans += dfs(s, l, i - 1, 1) * dfs(s, i + 1, r, 1);
                    ans += dfs(s, l, i - 1, 1) * dfs(s, i + 1, r, 0);
                }
            } else if (s[i] == '^') {
                if (x == 0) {
                    ans += dfs(s, l, i - 1, 0) * dfs(s, i + 1, r, 0);
                    ans += dfs(s, l, i - 1, 1) * dfs(s, i + 1, r, 1);
                } else {
                    ans += dfs(s, l, i - 1, 0) * dfs(s, i + 1, r, 1);

                    ans += dfs(s, l, i - 1, 1) * dfs(s, i + 1, r, 0);
                }
            } else if (s[i] == '&') {
                if (x == 0) {
                    ans += dfs(s, l, i - 1, 0) * dfs(s, i + 1, r, 0);
                    ans += dfs(s, l, i - 1, 0) * dfs(s, i + 1, r, 1);
                    ans += dfs(s, l, i - 1, 1) * dfs(s, i + 1, r, 0);
                } else {
                    ans += dfs(s, l, i - 1, 1) * dfs(s, i + 1, r, 1);
                }
            }
        }
        return dp[l][r][x] = ans;
    }
    int countEval(string s, int result) {
        int l = s.length();
        return dfs(s, 0, l - 1, result);
    }
};