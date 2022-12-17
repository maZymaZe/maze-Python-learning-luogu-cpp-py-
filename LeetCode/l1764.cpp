class Solution {
   public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int p1 = 0, p2 = 0, p3 = 0, l2 = groups.size(), l1 = nums.size(), l3;
        while (p2 < l2) {
            p3 = 0;
            while (p1 < l1 && groups[p2][p3] != nums[p1])
                p1++;

            l3 = groups[p2].size();
            if (p1 + l3 > l1)
                return false;
            int flag = 1;
            for (int i = 0; i < l3; i++) {
                if (groups[p2][i] != nums[p1 + i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                p2++;
                p1 += l3;
            } else {
                p1++;
            }
        }
        return true;
    }
};