class Solution {
   public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int l = points.size();
        int ans = 0;
        unordered_map<int, int> s;
        for (int i = 0; i < l; i++) {
            s.clear();
            for (int j = 0; j < l; j++) {
                int dis = (points[i][0] - points[j][0]) *
                              (points[i][0] - points[j][0]) +
                          (points[i][1] - points[j][1]) *
                              (points[i][1] - points[j][1]);
                if (s.count(dis))
                    ans += 2 * s[dis];
                s[dis]++;
            }
        }
        return ans;
    }
};