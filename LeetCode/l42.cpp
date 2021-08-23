class Solution {
   public:
    int trap(vector<int>& height) {
        int l = height.size();
        vector<int> lc(l), rc(l);
        lc[0] = height[0];
        for (int i = 1; i < l; i++)
            lc[i] = max(lc[i - 1], height[i]);
        rc[l - 1] = height[l - 1];
        for (int i = l - 2; i >= 0; i--)
            rc[i] = max(rc[i + 1], height[i]);
        int ans = 0;
        for (int i = 0; i < l; i++)
            ans += min(rc[i], lc[i]) - height[i];
        return ans;
    }
};