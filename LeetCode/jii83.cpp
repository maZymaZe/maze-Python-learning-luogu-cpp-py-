class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> a;
        a.push_back(nums);
        long long l = 1;
        int ll = nums.size();
        for (int i = 1; i <= nums.size(); i++)
            l *= i;
        for (int i = 1; i < l; i++) {
            next_permutation(nums.begin(), nums.end());
            a.push_back(nums);
        }
        return a;
    }
};