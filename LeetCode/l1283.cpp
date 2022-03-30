class Solution {
   public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e7;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int tot = 0;
            for (int i : nums) {
                tot += (i + mid - 1) / mid;
            }
            if (tot <= threshold)
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};