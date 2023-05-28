class Solution {
   public:
    int averageValue(vector<int>& nums) {
        int c = 0, x = 0;
        for (int i : nums) {
            if (i % 6 == 0)
                c++, x += i;
        }
        if (!c)
            return 0;
        return x / c;
    }
};