class Solution {
   public:
    int maximumScore(vector<int>& nums, int k) {
        vector<int> v, p;
        int l = nums.size();
        int ans = 0;
        v.push_back(-1);
        p.push_back(-1);
        for (int i = 0; i < l; i++) {
            int b = i;
            while (nums[i] < v.back()) {
                b = p.back();
                if (b <= k && i - 1 >= k)
                    ans = max(ans, (i - b) * v.back());
                v.pop_back();
                p.pop_back();
            }
            if (nums[i] == v.back())
                continue;
            v.push_back(nums[i]);
            p.push_back(b);
        }
        int ll = v.size();
        for (int i = 1; i < ll; i++) {
            if (p[i] <= k)
                ans = max(ans, (l - p[i]) * v[i]);
        }
        return ans;
    }
};