class Solution {
   public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int l = nums1.size();
        vector<int> ns(l), ans(l);
        for (int i = 0; i < l; i++)
            ns[i] = i;
        sort(ns.begin(), ns.end(),
             [&](const int& a, const int& b) { return nums2[a] < nums2[b]; });
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1 = 0, p2 = 0, q2 = l - 1;
        while (p1 < l) {
            if (nums1[p1] > nums2[p2]) {
                ans[ns[p2]] = nums1[p1];
                p2++;
            } else {
                ans[ns[q2]] = nums1[p1];
                q2--;
            }
            p1++;
        }
        return ans;
    }
};