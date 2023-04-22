class Solution {
   public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int l = books.size();

        vector<int> dp(l + 1);
        dp[0] = 0;
        for (int i = 1; i <= l; i++) {
            dp[i] = dp[i - 1] + books[i - 1][1];
            int w = books[i - 1][0], th = books[i - 1][1];

            for (int j = i - 2; j >= 0; j--) {
                w += books[j][0], th = max(th, books[j][1]);
                if (w <= shelfWidth) {
                    dp[i] = min(dp[i], dp[j] + th);
                } else
                    break;
            }
        }
        return dp[l];
    }
};