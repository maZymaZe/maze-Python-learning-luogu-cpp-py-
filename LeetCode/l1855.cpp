class Solution {
   public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0, l1 = nums1.size(), l2 = nums2.size(), ans = 0;
        while (p1 < l1) {
            if (p2 < l2 && nums1[l1 - 1] > nums2[p2])
                break;
            while (p2 < l2 && nums2[p2] >= nums1[p1]) {
                p2++;
            }
            ans = max(p2 - 1 - p1, ans);
            p1++;
        }
        return ans;
    }
};