class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int i : nums)
            x ^= i;
        int d = 1;
        while (!(d & x))
            d <<= 1;
        int a = 0, b = 0;
        for (int i : nums)
            if (i & d)
                a ^= i;
            else
                b ^= i;
        return {a, b};
    }
};