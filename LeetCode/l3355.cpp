class Solution {
   public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = nums.size();
        vector<int> pre(l + 2, 0);
        for (const vector<int>& query : queries) {
            int l = query[0], r = query[1];
            pre[l] += 1;
            pre[r + 1] -= 1;
        }
        int cur = 0;
        for (int i = 0; i < l; i++) {
            cur += pre[i];
            if (cur < nums[i]) {
                return false;
            }
        }
        return true;
    }
};