#include <iostream>
using namespace std;
long long dp[100][100];

int main() {
    int n, h;
    cin >> n >> h;
    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < j; k++) {
                dp[j][i] += dp[k][i - 1] * dp[j - k - 1][i - 1];
            }
        }
    }
    cout << dp[n][n] - dp[n][h - 1] << endl;
    return 0;
}