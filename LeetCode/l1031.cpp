class Solution {
   public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int l = nums.size(), ans = 0;
        for (int k = 0; k < 2; k++) {
            vector<int> l1(l);
            int tot = 0;
            for (int i = 0; i < firstLen; i++) {
                tot += nums[i];
            }
            l1[firstLen - 1] = tot;
            for (int i = firstLen; i < l; i++) {
                tot += nums[i] - nums[i - firstLen];
                l1[i] = max(l1[i - 1], tot);
            }
            tot = 0;
            for (int i = 0; i < secondLen; i++) {
                tot += nums[l - i - 1];
            }
            int m = tot;
            for (int i = l - secondLen - 1; i >= firstLen - 1; i--) {
                ans = max(ans, l1[i] + m);
                tot += nums[i] - nums[i + secondLen];
                m = max(m, tot);
            }
            swap(firstLen, secondLen);
        }
        return ans;
    }
};