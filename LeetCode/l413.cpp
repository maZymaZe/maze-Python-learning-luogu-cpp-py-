class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int l = nums.size();
        vector<int> del(l - 1);
        for (int i = 0; i < l - 1; i++) {
            del[i] = nums[i + 1] - nums[i];
        }
        int pre = 0, cnt, ans = 0;
        for (int i = 1; i < l - 1; i++) {
            if (del[i] != del[i - 1]) {
                cnt = i - pre;
                if (cnt > 1) {
                    ans += (long long)(1 + cnt - 1) * (cnt - 1) / 2;
                }
            }
        }
        cnt = l - 1 - pre;
        if (cnt > 1) {
            ans += (long long)(1 + cnt - 1) * (cnt - 1) / 2;
        }
        return ans;
    }
};