class Solution {
   public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = -1, mc = 0;
        for (auto i : nums) {
            if (i % 2 == 0) {
                m[i]++;
                if (m[i] > mc || (m[i] == mc && i < ans)) {
                    ans = i, mc = m[i];
                }
            }
        }
        return ans;
    }
};