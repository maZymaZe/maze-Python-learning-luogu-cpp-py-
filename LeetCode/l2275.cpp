class Solution {
   public:
    int largestCombination(vector<int>& candidates) {
        int c[100] = {0};
        for (int i : candidates) {
            int p = 0;
            while (i) {
                c[++p] += i % 2;
                i /= 2;
            }
        }
        int ans = 1;
        for (int i = 0; i < 70; i++) {
            ans = max(ans, c[i]);
        }
        return ans;
    }
};