class Solution {
   public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int l = nums.size(), ma = -1;
        vector<int> ps(l + 1);
        for (int i = 0; i < l; i++) {
            ps[i + 1] = ps[i] + nums[i];
        }
        vector<int> prem(l + 1), sufm(l + 1), ans, kp(l + 1), ks(l + 1);
        for (int i = k + 1; i <= l; i++) {
            if (prem[i - 1] >= ps[i - 1] - ps[i - 1 - k]) {
                prem[i] = prem[i - 1];
                kp[i] = kp[i - 1];
            } else {
                prem[i] = ps[i - 1] - ps[i - 1 - k];
                kp[i] = i - k;
            }
        }
        for (int i = l - k; i >= 1; i--) {
            if (sufm[i + 1] > ps[i + k] - ps[i]) {
                sufm[i] = sufm[i + 1];
                ks[i] = ks[i + 1];
            } else {
                sufm[i] = ps[i + k] - ps[i];
                ks[i] = i + 1;
            }
        }
        for (int i = k + 1; i + k + k - 1 <= l; i++) {
            if (prem[i] + ps[i + k - 1] - ps[i - 1] + sufm[i + k - 1] > ma) {
                ma = prem[i] + ps[i + k - 1] - ps[i - 1] + sufm[i + k - 1];
                ans = {kp[i] - 1, i - 1, ks[i + k - 1] - 1};
            }
        }
        return ans;
    }
};