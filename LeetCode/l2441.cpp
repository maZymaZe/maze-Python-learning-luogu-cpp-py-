class Solution {
   public:
    int findMaxK(vector<int>& nums) {
        int v[1002] = {0};
        for (int i : nums) {
            if (i > 0)
                v[i] |= 1;
            else
                v[-i] |= 2;
        }

        for (int i = 1000; i > 0; i--) {
            if (v[i] == 3)
                return i;
        }
        return -1;
    }
};