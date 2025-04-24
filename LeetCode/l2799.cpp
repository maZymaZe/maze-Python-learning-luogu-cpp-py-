class Solution {
   public:
    int countCompleteSubarrays(vector<int>& nums) {
        int vis[2003] = {0}, n = nums.size(), ans = 0, tp = 0;
        for (int i : nums) {
            if (!vis[i]) {
                tp++;
            }
            vis[i]++;
        }
        int l = 0, r = 0, cur = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            vis[nums[i]]++;
            if (vis[nums[i]] == 1) {
                cur++;
            }
            while (cur == tp) {
                vis[nums[l]]--;
                if (vis[nums[l]] == 0) {
                    cur--;
                }
                l++;
            }
            ans += l;
        }
        return ans;
    }
};