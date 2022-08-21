class Solution {
   public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        for (int i = 0; i + 1 < l; i += 2)
            swap(nums[i], nums[i + 1]);
    }
};