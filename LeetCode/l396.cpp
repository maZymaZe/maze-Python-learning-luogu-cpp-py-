class Solution {
   public:
    int maxRotateFunction(vector<int>& nums) {
        long long ans = 0, tot = 0, mx = -1e18;
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            ans += 1ll * i * nums[i];
            tot += nums[i];
        }
        mx = max(mx, ans);
        for (int i = 1; i < l; i++) {
            ans += tot;
            ans -= 1ll * l * (nums[l - i]);
            mx = max(ans, mx);
        }
        return mx;
    }
};