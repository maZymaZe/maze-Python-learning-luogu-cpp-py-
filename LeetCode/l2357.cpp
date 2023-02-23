class Solution {
   public:
    int minimumOperations(vector<int>& nums) {
        int c[101] = {0}, ans = 0;
        for (auto i : nums) {
            c[i]++;
        }
        for (int i = 1; i <= 100; i++)
            ans += (c[i] > 0);
        return ans;
    }
};