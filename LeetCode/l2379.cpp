class Solution {
   public:
    int minimumRecolors(string blocks, int k) {
        int l = blocks.size();
        vector<int> ps(l + 1);
        for (int i = 0; i < l; i++) {
            ps[i + 1] = ps[i] + (blocks[i] == 'B');
        }
        int ans = k;
        for (int i = 0; i + k <= l; i++) {
            ans = min(ans, k - ps[i + k] + ps[i]);
        }
        return ans;
    }
};