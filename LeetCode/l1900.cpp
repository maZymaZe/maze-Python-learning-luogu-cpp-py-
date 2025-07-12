class Solution {
   private:
    int F[30][30][30], G[30][30][30];

   public:
    pair<int, int> dp(int n, int f, int s) {
        if (F[n][f][s]) {
            return {F[n][f][s], G[n][f][s]};
        }
        if (f + s == n + 1) {
            return {1, 1};
        }

        // F(n,f,s)=F(n,n+1-s,n+1-f)
        if (f + s > n + 1) {
            tie(F[n][f][s], G[n][f][s]) = dp(n, n + 1 - s, n + 1 - f);
            return {F[n][f][s], G[n][f][s]};
        }

        int earlist = INT_MAX, latest = INT_MIN;
        int n_half = (n + 1) / 2;

        if (s <= n_half) {
            // 在左侧或者中间
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s - f; ++j) {
                    auto [x, y] = dp(n_half, i + 1, i + j + 2);
                    earlist = min(earlist, x);
                    latest = max(latest, y);
                }
            }
        } else {
            // s 在右侧
            // s'
            int s_prime = n + 1 - s;
            int mid = (n - 2 * s_prime + 1) / 2;
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s_prime - f; ++j) {
                    auto [x, y] = dp(n_half, i + 1, i + j + mid + 2);
                    earlist = min(earlist, x);
                    latest = max(latest, y);
                }
            }
        }

        return {F[n][f][s] = earlist + 1, G[n][f][s] = latest + 1};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        memset(F, 0, sizeof(F));
        memset(G, 0, sizeof(G));

        // F(n,f,s) = F(n,s,f)
        if (firstPlayer > secondPlayer) {
            swap(firstPlayer, secondPlayer);
        }

        auto [earlist, latest] = dp(n, firstPlayer, secondPlayer);
        return {earlist, latest};
    }
};
