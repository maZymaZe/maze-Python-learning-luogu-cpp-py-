class Solution {
   public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int l = 0, r = 1e6 + 1, mid, len = nums.size();
        sort(nums.begin(), nums.end());
        while (l + 1 < r) {
            mid = (l + r) / 2;
            int cnt = 0;
            for (int i = 0; i < len; i++) {
                cnt += (upper_bound(nums.begin(), nums.end(), nums[i] + mid) -
                        nums.begin() - i - 1);
            }
            if (cnt >= k)
                r = mid;
            else
                l = mid;
        }
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            cnt += (upper_bound(nums.begin(), nums.end(), nums[i] + l) -
                    nums.begin() - i - 1);
        }
        if (cnt >= k)
            return l;
        return r;
    }
};