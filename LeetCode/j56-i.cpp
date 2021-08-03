class Solution {
   public:
    vector<int> singleNumbers(vector<int>& nums) {
        int t = 0;
        for (int i : nums)
            t ^= i;
        t = (-t) & t;
        int t1 = 0, t2 = 0;
        for (int i : nums)
            (i & t) ? t1 ^= i : t2 ^= i;
        return {t1, t2};
    }
};