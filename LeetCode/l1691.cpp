class Solution {
   public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int l = cuboids.size();
        for (int i = 0; i < l; i++)
            sort(cuboids[i].begin(), cuboids[i].end());
        sort(cuboids.begin(), cuboids.end(), [](const auto& a, const auto& b) {
            return pair(a[2], a[1] + a[0]) < pair(b[2], b[1] + b[0]);
        });
        vector<int> f(l);
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < i; j++) {
                if (cuboids[j][0] <= cuboids[i][0] &&
                    cuboids[j][1] <= cuboids[i][1] &&
                    cuboids[j][2] <= cuboids[i][2])
                    f[i] = max(f[i], f[j]);
            }
            f[i] += cuboids[i][2];
        }
        int ans = 0;
        for (int i = 0; i < l; i++)
            ans = max(ans, f[i]);
        return ans;
    }
};