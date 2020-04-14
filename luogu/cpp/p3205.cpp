#include <cstdio>
int n, a[1030], dp[1030][1030][2] = {0};
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        dp[i][1][0] = 1;
        dp[i][1][1] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            if (i == 2) {
                if(a[j+1]>a[j])dp[j][i][1]=dp[j][i-1][0];
                if(a[j+1]>a[j])dp[j][i][0]=dp[j+1][i-1][0];
            } else {
                if (a[j + i - 1] > a[j + i - 2])
                    dp[j][i][1] = (dp[j][i - 1][1] + dp[j][i][1]) % 19650827;
                if (a[j + i - 1] > a[j])
                    dp[j][i][1] = (dp[j][i - 1][0] + dp[j][i][1]) % 19650827;
                if (a[j] < a[j + 1])
                    dp[j][i][0] =
                        (dp[j][i][0] + dp[j + 1][i - 1][0]) % 19650827;
                if (a[j] < a[j + i - 1])
                    dp[j][i][0] =
                        (dp[j][i][0] + dp[j + 1][i - 1][1]) % 19650827;
            }
        }
       
    } 
    printf("%d",(dp[1][n][0]+dp[1][n][1])% 19650827);
    return 0;
}