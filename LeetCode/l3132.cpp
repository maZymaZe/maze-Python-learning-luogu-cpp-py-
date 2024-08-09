class Solution {
   public:
    bool match(const vector<int>& a, const vector<int>& b, int x) {
        int l1 = a.size(), l2 = b.size(), p1 = 0, p2 = 0;
        while (p1 < l1 && p2 < l2) {
            if (a[p1] + x == b[p2])
                p1++, p2++;
            else
                p1++;
        }
        return p2 == l2;
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i < 3; i++) {
            if (match(nums1, nums2, nums2[0] - nums1[2 - i]))
                return nums2[0] - nums1[2 - i];
        }
        return 0;
    }
};