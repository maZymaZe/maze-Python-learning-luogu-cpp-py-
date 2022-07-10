class Solution {
   public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int l = nums.size();
        nth_element(nums.begin(), nums.begin() + (l - k), nums.end(),
                    [](const string& a, const string& b) {
                        if (a.size() == b.size())
                            return a < b;
                        return a.size() < b.size();
                    });
        return *(nums.begin() + (l - k));
    }
};