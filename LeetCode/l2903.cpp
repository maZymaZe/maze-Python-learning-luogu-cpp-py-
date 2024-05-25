class Solution {
   public:
    vector<int> findIndices(vector<int>& nums,
                            int indexDifference,
                            int valueDifference) {
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            for (int j = i + indexDifference; j < l; j++) {
                if (abs(nums[i] - nums[j]) >= valueDifference) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};