class Solution {
   public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int l = rectangles.size();
        map<pair<int, int>, int> mp;
        for (int i = 0; i < l; i++) {
            int gd = __gcd(rectangles[i][0], rectangles[i][1]);
            mp[{rectangles[i][0] / gd, rectangles[i][1] / gd}]++;
        }
        long long ans = 0;
        for (const auto& x : mp) {
            long long t = x.second;
            ans += (t - 1) * t / 2;
        }
        return ans;
    }
};