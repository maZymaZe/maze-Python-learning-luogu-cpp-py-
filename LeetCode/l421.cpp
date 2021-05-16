class Solution {
   public:
    int findMaximumXOR(vector<int>& nums) {
        int x = 0;
        for (int k = 30; k >= 0; k--) {
            unordered_set<int> seen;
            for (int i : nums)
                seen.insert(i >> k);
            int nx = x * 2 + 1;
            bool f = 0;
            for (int i : nums) {
                if (seen.count(nx ^ (i >> k))) {
                    f = 1;
                    break;
                }
            }
            if (f) {
                x = nx;
            } else {
                x = nx - 1;
            }
        }
        return x;
    }
};