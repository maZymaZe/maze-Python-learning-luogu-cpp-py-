class Solution {
   public:
    int smallestEqual(vector<int>& nums) {
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            if (nums[i] == i % 10)
                return i;
        }
        return -1;
    }
};