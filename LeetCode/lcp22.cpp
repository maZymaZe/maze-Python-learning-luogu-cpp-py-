class Solution {
   public:
    int cab(int a, int b) {
        int ans = 1;
        for (int i = 1; i <= a; i++)
            ans *= i;
        for (int i = 1; i <= b; i++)
            ans /= i;
        for (int i = 1; i <= (a - b); i++)
            ans /= i;
        return ans;
    }
    int paintingPlan(int n, int k) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                if (j == n && i != 0)
                    break;
                if ((i + j) * n - i * j == k) {
                    ans += cab(n, i) * cab(n, j);
                }
            }
        }
        return ans;
    }
};