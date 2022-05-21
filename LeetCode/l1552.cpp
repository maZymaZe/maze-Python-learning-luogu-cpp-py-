class Solution {
   public:
    int maxDistance(vector<int>& position, int m) {
        int l = 1, r = 1e9 + 7, mid, len = position.size();
        sort(position.begin(), position.end());
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            int c = 1, p = position[0];
            for (int i = 1; i < len; i++) {
                if (position[i] - p >= mid) {
                    p = position[i];
                    c++;
                }
            }
            if (c >= m)
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};