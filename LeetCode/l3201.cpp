class Solution {
   public:
    int maximumLength(vector<int>& nums) {
        int r = 2, a[3] = {0};
        for (int i : nums) {
            a[i % 2]++;
            if (i % 2 != r) {
                a[2]++;
            }
            r = i % 2;
        }
        return max({a[0], a[1], a[2]});
    }
};