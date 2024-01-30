class Solution {
   public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int l = nums.size();
        int c1 = 0, c2 = 0, v1[51] = {0}, v2[51] = {0};
        int a1[51] = {0}, a2[51] = {0};
        for (int i = 0; i < l; i++) {
            if (!v1[nums[i]]) {
                c1++, v1[nums[i]] = 1;
            }
            a1[i] = c1;
        }
        for (int i = l - 1; i >= 0; i--) {
            a2[i] = c2;
            if (!v2[nums[i]]) {
                c2++, v2[nums[i]] = 1;
            }
        }
        vector<int> ans(l);
        for (int i = 0; i < l; i++)
            ans[i] = a1[i] - a2[i];
        return ans;
    }
};