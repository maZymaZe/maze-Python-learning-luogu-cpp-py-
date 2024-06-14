class Solution {
   public:
    long long maxScore(vector<int>& nums, int x) {
        long long edm = -1, odm = -1;
        int l = nums.size(), p = 1;
        if (nums[0] % 2 == 0) {
            edm = nums[0];
            while (p < l && nums[p] % 2 == 0) {
                edm += nums[p];
                p++;
            }
            if (p == l)
                return edm;
            odm = edm + nums[p] - x;
        } else {
            odm = nums[0];
            while (p < l && nums[p] % 2 == 1) {
                odm += nums[p];
                p++;
            }
            if (p == l)
                return odm;
            edm = odm + nums[p] - x;
        }

        for (int i = p + 1; i < l; i++) {
            if (nums[i] % 2 == 0) {
                edm = max(edm + nums[i], odm + nums[i] - x);
            } else {
                odm = max(odm + nums[i], edm + nums[i] - x);
            }
        }
        return max(odm, edm);
    }
};