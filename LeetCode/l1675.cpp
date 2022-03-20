class Solution {
   public:
    int minimumDeviation(vector<int>& nums) {
        int l = nums.size(), res = INT_MAX, mi = INT_MAX;
        for (int i = 0; i < l; i++) {
            if (nums[i] & 1)
                nums[i] *= 2;
            mi = min(mi, nums[i]);
        }
        priority_queue<int> pq(nums.begin(), nums.end());
        while (pq.top() % 2 == 0) {
            res = min(res, pq.top() - mi);
            mi = min(mi, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
        }
        return min(res, pq.top() - mi);
    }
};