class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<int> v;
        vector<string> ans;
        if(nums.empty())return ans;
        for (int i : nums) {
            if (v.empty())
                v.push_back(i);
            else if (v.back() + 1 == i)
                v.push_back(i);
            else {
                if (v.size() == 1)
                    ans.push_back(to_string(v[0]));
                else {
                    ans.push_back(to_string(v.front()) + "->" +
                                  to_string(v.back()));
                }
                v.clear();
                v.push_back(i);
            }
        }
        if (v.size() == 1)
            ans.push_back(to_string(v[0]));
        else {
            ans.push_back(to_string(v.front()) + "->" + to_string(v.back()));
        }
        return ans;
    }
};