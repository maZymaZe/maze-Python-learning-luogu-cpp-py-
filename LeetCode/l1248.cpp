class Solution {
   public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = nums.size();
        vector<int> ps(l + 1), b(l + 1);
        for (int i = 1; i <= l; i++) {
            ps[i] = ps[i - 1] + (nums[i - 1] & 1);
        }
        for (int i = 0; i <= l; i++)
            b[ps[i]]++;
        int ans = 0;
        for (int i = 0; i + k <= l; i++) {
            ans += b[i] * b[i + k];
        }
        return ans;
    }
};