class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int l = nums.size();
        if (l == 0)
            return result;
        int d1 = nums[0], c1 = 0, c2 = 0, d2 = nums[0];
        for (int i : nums) {
            if (d1 == i) {
                c1++;
                continue;
            }
            if (d2 == i) {
                c2++;
                continue;
            }
            if (c1 == 0) {
                d1 = i, c1++;
                continue;
            }
            if (c2 == 0) {
                d2 = i, c2++;
                continue;
            }
            c1--, c2--;
        }
        c1 = c2 = 0;
        for (int i : nums) {
            if (d1 == i)
                c1++;
            else if (d2 == i)
                c2++;
        }
        if (c1 > l / 3)
            result.push_back(d1);
        if (c2 > l / 3)
            result.push_back(d2);
        return result;
    }
};