class Solution {
   public:
    int sumOfBeauties(vector<int>& nums) {
        int l = nums.size();
        vector<int> mi(l);
        mi[0] = nums[0];
        for (int i = 1; i < l; i++)
            mi[i] = max(mi[i - 1], nums[i]);
        int ma = nums[l - 1], ans = 0;
        for (int i = l - 2; i > 0; i--) {
            if (nums[i] < ma && nums[i] > mi[i - 1])
                ans += 2;
            else if (nums[i] < nums[i + 1] && nums[i] > nums[i - 1])
                ans++;
            ma = min(ma, nums[i]);
        }
        return ans;
    }
};