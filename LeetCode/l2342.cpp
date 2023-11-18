class Solution {
   public:
    int maximumSum(vector<int>& nums) {
        vector<int> c[100];
        int ans = -1;
        for (int i : nums) {
            int t = 0, ti = i;
            while (ti) {
                t += ti % 10;
                ti /= 10;
            }
            c[t].push_back(i);
        }
        for (int i = 0; i < 100; i++) {
            if (c[i].size() > 1) {
                sort(c[i].begin(), c[i].end());
                ans = max(ans, c[i][c[i].size() - 1] + c[i][c[i].size() - 2]);
            }
        }
        return ans;
    }
};