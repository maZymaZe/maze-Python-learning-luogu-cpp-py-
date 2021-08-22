class Solution {
   public:
    bool isMajorityElement(vector<int>& nums, int target) {
        return (upper_bound(nums.begin(), nums.end(), target) -
                    lower_bound(nums.begin(), nums.end(), target) >
                (nums.size() / 2));
    }
};