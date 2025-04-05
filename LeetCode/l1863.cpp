class Solution {
   public:
    vector<int> v;
    int n;
    int ans = 0;
    void dfs(int x, int y) {
        if (x == n) {
            ans += y;
            return;
        }
        dfs(x + 1, y);
        dfs(x + 1, y ^ v[x]);
    }
    int subsetXORSum(vector<int>& nums) {
        v = nums;
        n = nums.size();
        dfs(0, 0);
        return ans;
    }
};