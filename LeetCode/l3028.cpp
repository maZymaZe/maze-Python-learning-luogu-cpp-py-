class Solution {
   public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for (int i = 0; i < k - 1; i++)
            colors.push_back(colors[i]);
        int l = colors.size(), ans = 0;
        int cur = colors[0], cnt = 1;
        for (int i = 1; i < l; i++) {
            if (colors[i] != cur) {
                cnt++;
            } else {
                cnt = 1;
            }
            cur = colors[i];
            if (cnt >= k)
                ans++;
        }
        return ans;
    }
};