struct PR {
    int pos, val;
};
class Solution {
   public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<PR> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {i, nums[i]};
        }
        sort(a.begin(), a.end(), [](const PR& x, const PR& y) {
            return x.val > y.val || (x.val == y.val && x.pos < y.pos);
        });
        vector<int> ans;
        sort(a.begin(), a.begin() + k,
             [](const PR& x, const PR& y) { return x.pos < y.pos; });
        for (int i = 0; i < k; i++) {
            ans.push_back(a[i].val);
        }
        return ans;
    }
};