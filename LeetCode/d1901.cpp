#include <cstdio>
long long dp[100][100][100][3];
long long dfs(long long a, long long b, long long c, long long d) {
    long long ans = 0;
    if (a == 0 && b == 0 && c == 0) {
        return 1;
    }
    if (dp[a][b][c][d])
        return dp[a][b][c][d];
    if (d != 1 && a)
        ans += dfs(a - 1, b, c, 1);
    if (d != 2 && b)
        ans += dfs(a, b - 1, c, 2);
    if (d != 3 && c)
        ans += dfs(a, b, c - 1, 3);
    dp[a][b][c][d] = ans;
    return ans;
}
int main() {
    long long c[3];
    for (long long i = 0; i < 3; i++)
        scanf("%lld", &c[i]);
    printf("%lld\n", dfs(c[0], c[1], c[2], 0));
    return 0;
}