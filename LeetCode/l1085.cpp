class Solution {
   public:
    int sumOfDigits(vector<int>& nums) {
        int mi = 0x7FFFFFFF;
        for (auto i : nums)
            mi = min(mi, i);
        int c = 0;
        while (mi) {
            c += mi % 10;
            mi /= 10;
        }
        return (c & 1) ^ 1;
    }
};