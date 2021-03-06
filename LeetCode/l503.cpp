class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int l = nums.size();
        vector<int> ans(l);
        deque<int> v;
        for (int i = l - 1; i >= 0; i--) {
            while (!v.empty() && nums[i] >= v.front()) {
                v.pop_front();
            }
            v.push_front(nums[i]);
        }
        for (int i = l - 1; i >= 0; i--) {
            if (!v.empty() && nums[i] >= v.back()) {
                ans[i] = -1;
            } else {
                int t = upper_bound(v.begin(), v.end(), nums[i]) - v.begin();
                ans[i]=v[t];
            }
            while (!v.empty() && nums[i] >= v.front()) {
                v.pop_front();
            }
            v.push_front(nums[i]);
        }
        return ans;
    }
};