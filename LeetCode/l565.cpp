class Solution {
   public:
    int arrayNesting(vector<int>& nums) {
        int l = nums.size(), ans = 0;
        vector<int> v(l);
        for (int i = 0; i < l; i++) {
            if (!v[i]) {
                v[i] = 1;
                int p = i, c = 1;
                while (!v[nums[p]]) {
                    v[nums[p]] = 1;
                    p = nums[p];
                    c++;
                }
                ans = max(ans, c);
            }
        }
        return ans;
    }
};