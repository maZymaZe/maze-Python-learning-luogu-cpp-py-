class Solution {
   public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int l = nums.size();
        vector<int> ans(l), ps(l + 1);
        for (int i = 0; i < l; i++)
            ps[i + 1] = ps[i] + nums[i];
        for (int i = 0; i < l; i++) {
            ans[i] = ps[l] - ps[i] - (l - i) * nums[i] + i * nums[i] - ps[i];
        }
        return ans;
    }
};