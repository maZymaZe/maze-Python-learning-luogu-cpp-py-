class Solution {
   public:
    int specialArray(vector<int>& nums) {
        int cnt[1001] = {0};
        for (int i : nums)
            cnt[i]++;
        for (int i = 999; i >= 0; i--) {
            cnt[i] += cnt[i + 1];
            if (i == cnt[i])
                return i;
        }
        return -1;
    }
};