class Solution {
   public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        return *max_element(nums2.begin(), nums2.end()) -
               *max_element(nums1.begin(), nums1.end());
    }
};