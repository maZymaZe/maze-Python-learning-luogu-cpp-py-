class Solution {
   public:
    map<int, int> mp;
    void dfs(vector<int>& nums, int x, int y) {
        if (x >= nums.size()) {
            mp[y]++;
            return;
        }
        dfs(nums, x + 1, y);
        dfs(nums, x + 1, y | nums[x]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        dfs(nums, 0, 0);
        return (--mp.end())->second;
    }
};