class Solution {
   public:
    int minimumOperations(vector<int>& nums) {
        int vis[102] = {0};
        int p = nums.size() - 1;
        while (p >= 0) {
            if (vis[nums[p]])
                break;
            vis[nums[p]]++;
            p--;
        }
        if (p == -1)
            return 0;
        return (p + 3) / 3;
    }
};