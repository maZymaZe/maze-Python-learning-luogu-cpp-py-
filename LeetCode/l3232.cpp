class Solution {
   public:
    bool canAliceWin(vector<int>& nums) {
        int tot = 0;
        for (int i : nums) {
            if (i > 9)
                tot += i;
            else
                tot -= i;
        }
        return tot != 0;
    }
};