class Solution {
   public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[102] = {0}, sum[102] = {0}, l = nums.size();
        for (int i = 0; i < l; i++)
            cnt[nums[i]]++;
        for (int i = 1; i <= 100; i++)
            sum[i] = sum[i - 1] + cnt[i - 1];
        vector<int> result(l);
        for (int i = 0; i < l; i++)
            result[i] = sum[nums[i]];
        return result;
    }
};