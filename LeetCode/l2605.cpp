class Solution {
   public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int a[10] = {0}, b[10] = {0};
        for (int i : nums1)
            a[i]++;
        for (int i : nums2)
            b[i]++;
        for (int i = 1; i < 10; i++)
            if (a[i] && b[i])
                return i;
        int ma = 10, mb = 10;
        for (int i : nums1)
            ma = min(ma, i);
        for (int i : nums2)
            mb = min(mb, i);
        return min(ma, mb) * 10 + max(ma, mb);
    }
};