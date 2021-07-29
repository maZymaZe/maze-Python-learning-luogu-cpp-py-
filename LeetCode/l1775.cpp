class Solution {
   public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size(), tot1 = 0, tot2 = 0,
            c1[7] = {0}, c2[7] = {0};
        int ps = 0;
        for (int i = 0; i < l1; i++)
            tot1 += nums1[i], c1[nums1[i]]++;
        for (int i = 0; i < l2; i++)
            tot2 += nums2[i], c2[nums2[i]]++;
        if (tot1 > tot2) {
            if (l2 * 6 < l1)
                return -1;
            int delta = tot1 - tot2;
            for (int i = 5; i > 0; i--) {
                int c = c1[i + 1] + c2[6 - i];
                if (c * i >= delta) {
                    return ps + (delta + i - 1) / i;
                } else {
                    ps += c;
                    delta -= c * i;
                }
            }
        } else if (tot1 < tot2) {
            if (l1 * 6 < l2)
                return -1;
            int delta = tot2 - tot1;
            for (int i = 5; i > 0; i--) {
                int c = c2[i + 1] + c1[6 - i];
                if (c * i >= delta) {
                    return ps + (delta + i - 1) / i;
                } else {
                    ps += c;
                    delta -= c * i;
                }
            }
        }
        return 0;
    }
};