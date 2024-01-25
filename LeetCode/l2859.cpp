class Solution {
   public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        auto bitCount = [](int x) {
            int cnt = 0;
            while (x) {
                cnt += (x % 2);
                x /= 2;
            }
            return cnt;
        };

        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (bitCount(i) == k) {
                ans += nums[i];
            }
        }
        return ans;
    }
};
