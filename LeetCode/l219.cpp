class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int l = nums.size();
        for (int i = 0; i <= k && i < l; i++) {
            if (st.count(nums[i]))
                return true;
            st.insert(nums[i]);
        }
        for (int i = 0; i + k + 1 < l; i++) {
            st.erase(nums[i]);
            if (st.count(nums[i + k + 1]))
                return true;
            st.insert(nums[i + k + 1]);
        }
        return false;
    }
};