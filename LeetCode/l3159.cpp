class Solution {
   public:
    vector<int> occurrencesOfElement(vector<int>& nums,
                                     vector<int>& queries,
                                     int x) {
        vector<int> c;
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            if (nums[i] == x)
                c.push_back(i);
        }
        vector<int> ans;
        for (int i : queries) {
            if (i > c.size())
                ans.push_back(-1);
            else
                ans.push_back(c[i - 1]);
        }
        return ans;
    }
};