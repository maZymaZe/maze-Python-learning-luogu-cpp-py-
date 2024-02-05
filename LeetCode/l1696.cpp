class Solution {
   public:
    int maxResult(vector<int>& nums, int k) {
        list<pair<int, int>> ls;
        ls.push_back({0, nums[0]});
        int l = nums.size(), ans = nums[0];
        for (int i = 1; i < l; i++) {
            if (ls.front().first + k < i)
                ls.pop_front();
            int nx = ls.front().second + nums[i];
            while (!ls.empty() && nx >= ls.back().second)
                ls.pop_back();
            ls.push_back({i, nx});
        }
        return ls.back().second;
    }
};