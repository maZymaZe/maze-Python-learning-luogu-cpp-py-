class Solution {
   public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int ans = 0x3f3f3f3f, l = timePoints.size();
        for (int i = 1; i < l; i++) {
            ans = min(ans, ((timePoints[i][0] - timePoints[i - 1][0]) * 10 +
                            (timePoints[i][1] - timePoints[i - 1][1])) *
                                   60 +
                               (timePoints[i][3] - timePoints[i - 1][3]) * 10 +
                               (timePoints[i][4] - timePoints[i - 1][4]));
        }
        ans = min(ans, ((timePoints[0][0] + 2 - timePoints[l - 1][0]) * 10 +
                        (timePoints[0][1] + 4 - timePoints[l - 1][1])) *
                               60 +
                           (timePoints[0][3] - timePoints[l - 1][3]) * 10 +
                           (timePoints[0][4] - timePoints[l - 1][4]));
        return ans;
    }
};