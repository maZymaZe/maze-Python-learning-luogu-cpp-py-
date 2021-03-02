class Solution {
   public:
    int getKthMagicNumber(int k) {
        vector<int> ans(k);
        int p[3] = {0};
        ans[0] = 1;
        for (int i = 1; i < k; i++) {
            ans[i] = min(ans[p[0]] * 3, min(ans[p[1]] * 5, ans[p[2]] * 7));
            if (ans[i] == ans[p[0]] * 3)
                p[0]++;
            if (ans[i] == ans[p[1]] * 5)
                p[1]++;
            if (ans[i] == ans[p[2]] * 7)
                p[2]++;
        }
        return ans[k - 1];
    }
};