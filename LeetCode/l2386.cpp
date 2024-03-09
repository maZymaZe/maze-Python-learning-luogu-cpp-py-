class Solution {
   public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long tot = 0;
        for (int& x : nums) {
            if (x >= 0)
                tot += x;
            else
                x = -x;
        }
        sort(nums.begin(), nums.end());
        long long ret = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;
        pq.push({nums[0], 0});
        for (int j = 2; j <= k; j++) {
            auto [t, i] = pq.top();
            pq.pop();
            ret = t;
            if (i == n - 1)
                continue;
            pq.push({t + nums[i + 1], i + 1});
            pq.push({t - nums[i] + nums[i + 1], i + 1});
        }
        return tot - ret;
    }
};