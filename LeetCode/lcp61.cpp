class Solution {
   public:
    int ck(int x, int y) {
        if (x > 0 && y > 0)
            return 1;
        if (x == 0 && y == 0)
            return 1;
        if (x < 0 && y < 0)
            return 1;
        return 0;
    }
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int ans = 0, cur = 0, l = temperatureA.size();
        for (int i = 1; i < l; i++) {
            if (ck(temperatureA[i] - temperatureA[i - 1],
                   temperatureB[i] - temperatureB[i - 1])) {
                cur++;
                ans = max(ans, cur);
            } else {
                cur = 0;
            }
        }
        return ans;
    }
};