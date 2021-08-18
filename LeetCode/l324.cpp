class Solution {
   public:
    void wiggleSort(vector<int>& nums) {
        int cnt[5003] = {0}, l = nums.size();
        for (auto i : nums) {
            cnt[i]++;
        }
        int lf = 0, p = (l & 1) ? (l - 1) : (l - 2);
        for (; p >= 0; p -= 2) {
            while (cnt[lf] == 0)
                lf++;
            nums[p] = lf;
            cnt[lf]--;
        }
        p = (l & 1) ? (l - 2) : (l - 1);
        for (; p >= 0; p -= 2) {
            while (cnt[lf] == 0)
                lf++;
            nums[p] = lf;
            cnt[lf]--;
        }
    }
};