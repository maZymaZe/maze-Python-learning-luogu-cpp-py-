class Solution {
   public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> g;
        vector<int> preSum(1, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                g.emplace_back(i - g.size());
                preSum.emplace_back(preSum.back() + g.back());
            }
        }
        int m = g.size(), res = INT_MAX;
        for (int i = 0; i <= m - k; i++) {
            int mid = i + k / 2;
            res = min(res, (1 - k % 2) * g[mid] +
                               (preSum[i + k] - preSum[mid + 1]) -
                               (preSum[mid] - preSum[i]));
        }
        return res;
    }
};
