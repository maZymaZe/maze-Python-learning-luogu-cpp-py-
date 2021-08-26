class Solution {
   public:
    int maxArea(vector<int>& height) {
        int l = height.size(), ans = 0;
        vector<int> lmp, ll;
        for (int i = 0; i < l; i++) {
            if (ll.empty() || height[i] > ll.back()) {
                ll.push_back(height[i]);
                lmp.push_back(i);
            }
        }
        for (int i = 0; i < l; i++) {
            int idx = lower_bound(ll.begin(), ll.end(), height[i]) - ll.begin();
            if (idx != ll.size() && lmp[idx] < i) {
                ans = max(ans, height[i] * (i - lmp[idx]));
            }
        }
        reverse(height.begin(), height.end());
        lmp.clear(), ll.clear();
        for (int i = 0; i < l; i++) {
            if (ll.empty() || height[i] > ll.back()) {
                ll.push_back(height[i]);
                lmp.push_back(i);
            }
        }
        for (int i = 0; i < l; i++) {
            int idx = lower_bound(ll.begin(), ll.end(), height[i]) - ll.begin();
            if (idx != ll.size() && lmp[idx] < i) {
                ans = max(ans, height[i] * (i - lmp[idx]));
            }
        }
        return ans;
    }
};