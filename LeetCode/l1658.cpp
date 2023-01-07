class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> e;
        int l = nums.size(), b = 0, ans = 0x3f3f3f3f;
        e[0] = 0;
        for (int i = 0; i < l; i++) {
            b += nums[l - i - 1];
            if (!e.count(b)) {
                e[b] = i + 1;
            }
        }
        b = 0;
        if (e.count(x))
            ans = min(ans, e[x]);
        for (int i = 0; i < l; i++) {
            b += nums[i];
            if (e.count(x - b)) {
                ans = min(ans, i + 1 + e[x - b]);
            }
        }
        if (ans > l)
            return -1;
        return ans;
    }
};