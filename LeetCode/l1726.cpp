class Solution {
   public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> mp;
        int l = nums.size(), ans = 0;
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                int x = nums[j] * nums[i];
                ans += mp[x];
                mp[x]++;
            }
        }
        return ans * 8;
    }
};