class Solution {
   public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        list<int> xs, xys;
        int l = points.size(), ans = -0x3f3f3f3f;
        for (int i = 0; i < l; i++) {
            while (!xs.empty() && points[i][0] - xs.back() > k)
                xs.pop_back(), xys.pop_back();
            if (xs.size() != 0) {
                ans = max(ans, xys.back() + points[i][0] + points[i][1]);
            }
            while (!xs.empty() && (points[i][1] - points[i][0] > xys.front())) {
                xs.pop_front();
                xys.pop_front();
            }
            xs.push_front(points[i][0]);
            xys.push_front(points[i][1] - points[i][0]);
        }
        return ans;
    }
};