class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> s;
        s.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > s.back()) {
                s.push_back(nums[i]);
            } else {
                auto p = upper_bound(s.begin(), s.end(), nums[i]);
                if (p != s.end() && (p == s.begin() || (*(p - 1)) < nums[i]))
                    (*p) = nums[i];
            }
        }
        return s.size();
    }
};