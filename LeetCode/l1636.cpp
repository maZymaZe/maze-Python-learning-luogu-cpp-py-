class Solution {
   public:
    vector<int> frequencySort(vector<int>& nums) {
        int x[202] = {0};
        for (auto i : nums) {
            x[i + 100]++;
        }
        sort(nums.begin(), nums.end(), [&](const int& a, const int& b) {
            if (x[a + 100] == x[b + 100])
                return a > b;
            return x[a + 100] < x[b + 100];
        });
        return nums;
    }
};