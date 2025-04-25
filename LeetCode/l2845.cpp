class Solution {
   public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = (nums[i] % modulo == k);
        }
        int cur = 0;
        vector<int> mo(min(modulo, n + 1));
        mo[0] = 1;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            cur = (cur + res[i]) % modulo;
            if ((cur - k + modulo) % modulo < mo.size())
                ans += mo[(cur - k + modulo) % modulo];
            mo[cur]++;
        }
        return ans;
    }
};