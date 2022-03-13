class Solution {
   public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> v;
        int l = nums.size();
        for (int i = 0; i < l; i++)
            v.insert(v.begin() + index[i], nums[i]);
        return v;
    }
};