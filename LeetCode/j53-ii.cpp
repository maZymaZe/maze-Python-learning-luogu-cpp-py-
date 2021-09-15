class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int l = nums.size();
        vector<int> c(l + 1);
        for (auto i : nums)
            c[i]++;
        for (int i = 0; i <= l; i++) {
            if (c[i] == 0)
                return i;
        }
        return -1;
    }
};