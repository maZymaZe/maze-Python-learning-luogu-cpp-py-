class Solution {
   public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
             });
        int n = intervals.size(), res = 0;
        vector<int> ovl(n, 2);
        while (n) {
            --n;
            int s = intervals[n][0], ol = ovl[n];
            for (int i = s; i < s + ol; i++) {
                for (int j = 0; j < n; j++) {
                    if (ovl[j] > 0 && i <= intervals[j][1]) {
                        --ovl[j];
                    }
                }
                ++res;
            }
        }
        return res;
    }
};