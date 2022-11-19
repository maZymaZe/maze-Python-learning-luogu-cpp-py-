class Solution {
   public:
    int largestAltitude(vector<int>& gain) {
        int x = 0, y = 0;
        for (auto z : gain) {
            x += z;
            y = max(x, y);
        }
        return y;
    }
};