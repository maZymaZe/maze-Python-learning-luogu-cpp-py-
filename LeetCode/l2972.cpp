class Solution {
   public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int pf = 1, l = nums.size();
        while (pf < l && nums[pf] > nums[pf - 1])
            pf++;
        if (pf == l) {
            return (long long)l * (l + 1) / 2;
        }
        int pe = l - 2;
        while (pe >= 0 && nums[pe] < nums[pe + 1])
            pe--;
        long long ans = 1;
        ans += pf + (l - pe - 1);

        pe++;
        for (int p = 0; p < pf; p++) {
            while (pe < l && nums[pe] <= nums[p])
                pe++;
            ans += (l - pe);
        }
        return ans;
    }
};