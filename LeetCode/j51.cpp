class Solution {
   public:
    int MAX;
    vector<int> ta;
    void add(int x) {
        while (x < MAX) {
            ta[x]++;
            x += (-x & x);
        }
    }
    int query(int x) {
        int r = 0;
        while (x) {
            r += ta[x];
            x -= (-x & x);
        }
        return r;
    }
    int reversePairs(vector<int>& nums) {
        int l = nums.size();
        MAX = 4 * l;
        ta.resize(MAX);
        vector<int> c = nums;
        sort(c.begin(), c.end());
        int lim = unique(c.begin(), c.end()) - c.begin();
        int ans = 0;
        for (int i = l - 1; i >= 0; i--) {
            ans += query(lower_bound(c.begin(), c.begin() + lim, nums[i]) -
                         c.begin());
            add(lower_bound(c.begin(), c.begin() + lim, nums[i]) - c.begin() +
                1);
        }
        return ans;
    }
};