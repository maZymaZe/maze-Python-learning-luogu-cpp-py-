class Solution {
   public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int ml = 0, ans = 0;
        for (const auto& rect : rectangles)
            ml = max(min(rect[0], rect[1]), ml);
        for (const auto& rect : rectangles)
            ans += (min(rect[0], rect[1]) == ml);
        return ans;
    }
};