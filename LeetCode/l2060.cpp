class Solution {
   private:
    int f[41][41][2][1000];

   public:
    bool possiblyEquals(string s1, string s2) {
        memset(f, -1, sizeof(f));
        int m = s1.size(), n = s2.size();

        function<bool(int, int, int, int)> dfs = [&](int i, int j, int which,
                                                     int rest) -> bool {
            // 记忆化
            if (f[i][j][which][rest] != -1) {
                return f[i][j][which][rest];
            }

            if (which == 0) {
                if (j == n) {
                    return f[i][j][which][rest] = (i == m && !rest);
                } else if (isalpha(s2[j])) {
                    if (!rest && i != m && isalpha(s1[i])) {
                        return f[i][j][which][rest] =
                                   (s1[i] == s2[j] ? dfs(i + 1, j + 1, 0, 0)
                                                   : false);
                    } else {
                        return f[i][j][which][rest] =
                                   (rest >= 1 ? dfs(i, j + 1, 0, rest - 1)
                                              : dfs(i, j + 1, 1, 1));
                    }
                } else {
                    int x = 0, k = j;
                    while (k < n && isdigit(s2[k])) {
                        x = x * 10 + (s2[k] - '0');
                        if ((rest >= x && dfs(i, k + 1, 0, rest - x)) ||
                            (rest < x && dfs(i, k + 1, 1, x - rest))) {
                            return f[i][j][which][rest] = true;
                        }
                        ++k;
                    }
                    return f[i][j][which][rest] = false;
                }
            } else {
                if (i == m) {
                    return f[i][j][which][rest] = (j == n && !rest);
                } else if (isalpha(s1[i])) {
                    if (!rest && j != n && isalpha(s2[j])) {
                        return f[i][j][which][rest] =
                                   (s1[i] == s2[j] ? dfs(i + 1, j + 1, 0, 0)
                                                   : false);
                    } else {
                        return f[i][j][which][rest] =
                                   (rest >= 1 ? dfs(i + 1, j, 1, rest - 1)
                                              : dfs(i + 1, j, 0, 1));
                    }
                } else {
                    int x = 0, k = i;
                    while (k < m && isdigit(s1[k])) {
                        x = x * 10 + (s1[k] - '0');
                        if ((rest >= x && dfs(k + 1, j, 1, rest - x)) ||
                            (rest < x && dfs(k + 1, j, 0, x - rest))) {
                            return f[i][j][which][rest] = true;
                        }
                        ++k;
                    }
                    return f[i][j][which][rest] = false;
                }
            }
        };

        return dfs(0, 0, 0, 0);
    }
};
