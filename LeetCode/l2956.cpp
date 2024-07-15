class Solution {
   public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp, mp2;
        int l1 = nums1.size(), l2 = nums2.size(), cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < l1; i++)
            mp[nums1[i]] = i;
        for (int i = 0; i < l2; i++) {
            if (mp.count(nums2[i]))
                cnt1++;
            mp2[nums2[i]] = i;
        }
        for (int i = 0; i < l1; i++) {
            if (mp2.count(nums1[i]))
                cnt2++;
        }
        return {cnt2, cnt1};
    }
};