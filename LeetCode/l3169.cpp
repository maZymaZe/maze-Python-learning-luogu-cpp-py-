class Solution {
   public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int cur = 1, ans = 0;
        sort(meetings.begin(), meetings.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        for (auto& m : meetings) {
            if (m[0] > cur) {
                ans += m[0] - cur;
            }
            cur = max(cur, m[1] + 1);
        }
        if (cur <= days) {
            ans += days - cur + 1;
        }
        return ans;
    }
};