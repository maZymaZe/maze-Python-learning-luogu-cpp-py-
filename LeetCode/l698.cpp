class Solution {
    int memo[1 << 16];

   public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1)
            return true;
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % k != 0)
            return false;
        sort(nums.rbegin(), nums.rend());  //降序更快
        if (nums[0] > s / k)
            return false;
        int n = nums.size(), target = s / k;
        memset(memo, -1, sizeof(memo));

        function<int(int, int, int)> dfs = [&](int state, int curSum,
                                               int restBucket) {
            if (restBucket == 1)
                return 1;
            if (memo[state] >= 0)
                return memo[state];
            if (curSum == target)
                return memo[state] = dfs(state, 0, restBucket - 1);
            for (int i = 0; i < n; ++i) {  //桶选球
                if (((state >> i) & 1) && curSum + nums[i] <= target) {
                    if (dfs(state ^ (1 << i), curSum + nums[i], restBucket))
                        return memo[state] = 1;
                }
            }
            return memo[state] = 0;
        };

        return dfs((1 << n) - 1, 0, k);
    }
};
