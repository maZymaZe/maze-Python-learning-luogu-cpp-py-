class Solution {
   public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int l = positions.size();
        vector<int> ans(l);
        for (int i = 0; i < l; i++) {
            int w = 0;
            for (int j = 0; j < i; j++) {
                if ((positions[j][0] >= positions[i][0] &&
                     positions[j][0] < positions[i][0] + positions[i][1]) ||
                    (positions[j][0] + positions[j][1] > positions[i][0] &&
                     positions[j][0] + positions[j][1] <=
                         positions[i][0] + positions[i][1]) ||
                    (positions[j][0] <= positions[i][0] &&
                     positions[i][0] + positions[i][1] <=
                         positions[j][0] + positions[j][1])) {
                    w = max(w, ans[j]);
                }
            }
            ans[i] = w + positions[i][1];
        }
        for (int i = 1; i < l; i++)
            ans[i] = max(ans[i], ans[i - 1]);
        return ans;
    }
};