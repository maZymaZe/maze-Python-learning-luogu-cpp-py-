class Solution {
   public:
    int countSubarrays(vector<int>& nums, int k) {
        int p = 0, l = nums.size();
        for (int i = 0; i < l; i++) {
            if (nums[i] == k) {
                p = i;
                break;
            }
        }
        int lt = 0, rt = 0;
        unordered_map<int, int> lm, rm;
        lm[0]++, rm[0]++;
        for (int i = p - 1; i >= 0; i--) {
            if (nums[i] > k)
                lt++;
            else
                lt--;
            lm[lt]++;
        }
        for (int i = p + 1; i < l; i++) {
            if (nums[i] > k)
                rt++;
            else
                rt--;
            rm[rt]++;
        }
        int ans = 0;
        for (auto it : lm) {
            ans += it.second * (rm[-it.first] + rm[-it.first + 1]);
        }
        return ans;
    }
};