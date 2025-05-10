class Solution {
   public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), c1 = 0, c2 = 0;
        long long tot1 = 0, tot2 = 0;
        for (int i = 0; i < n1; i++) {
            if (nums1[i] == 0) {
                c1++;
                tot1 += 1;
            } else {
                tot1 += nums1[i];
            }
        }
        for (int i = 0; i < n2; i++) {
            if (nums2[i] == 0) {
                c2++;
                tot2 += 1;
            } else {
                tot2 += nums2[i];
            }
        }
        if (tot1 > tot2) {
            swap(tot1, tot2);
            swap(c1, c2);
        }
        if (tot1 == tot2) {
            return tot1;
        }
        if (c1 == 0) {
            return -1;
        }
        return tot2;
    }
};