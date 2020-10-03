class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            if (mp.count(nums[i]))
                return {mp[nums[i]], i};
            else
                mp.insert({target - nums[i], i});
        }
        return {};
    }
};