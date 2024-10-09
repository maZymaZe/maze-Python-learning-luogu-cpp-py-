class Solution {
   public:
    int minimumDifference(vector<int>& nums, int k) {
        int l = 0, cur = 0, n = nums.size(), ans = 0x3f3f3f3f;
        int cnt[40] = {0};
        for (int i = 0; i < n; i++) {
            int t = nums[i], p = 0;
            while (t) {
                cnt[p] += t % 2;
                if ((t % 2) && cnt[p] == 1)
                    cur += (1 << p);
                t /= 2;
                p++;
            }
            ans = min(ans, abs(cur - k));
            while (l <= i && cur > k) {
                t = nums[l], p = 0;
                while (t) {
                    cnt[p] -= t % 2;
                    if ((t % 2) && cnt[p] == 0)
                        cur -= (1 << p);
                    t /= 2;
                    p++;
                }
                if (l != i)
                    ans = min(ans, abs(cur - k));
                l++;
            }
        }
        return ans;
    }
};