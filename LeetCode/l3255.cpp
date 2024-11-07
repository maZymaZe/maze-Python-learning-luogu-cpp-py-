class Solution {
   public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        list<int> pos, v;
        for (int i = 0; i < k; i++) {
            while (!v.empty() && nums[i] <= v.back()) {
                v.pop_back();
                pos.pop_back();
            }
            v.push_back(nums[i]);
            pos.push_back(i);
        }
        if (v.size() == k && nums[k - 1] == nums[0] + k - 1) {
            ans[0] = nums[k - 1];
        } else
            ans[0] = -1;
        for (int i = k; i < n; i++) {
            if (pos.front() == i - k) {
                pos.pop_front();
                v.pop_front();
            }
            while (!v.empty() && nums[i] <= v.back()) {
                v.pop_back();
                pos.pop_back();
            }
            v.push_back(nums[i]);
            pos.push_back(i);
            if (v.size() == k && v.back() == v.front() + k - 1) {
                ans[i - k + 1] = v.back();
            } else
                ans[i - k + 1] = -1;
        }
        return ans;
    }
};