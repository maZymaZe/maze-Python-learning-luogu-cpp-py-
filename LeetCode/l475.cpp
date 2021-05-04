class Solution {
   public:
    bool ck(vector<int>& houses, vector<int>& heaters, int x) {
        int l = houses.size();
        for (int i = 0; i < l; i++) {
            int f = 0;
            auto it = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            if (it != heaters.end()) {
                if (houses[i] + x >= *it)
                    f |= 1;
            }
            if (it != heaters.begin()) {
                --it;
                if (houses[i] - x <= *it)
                    f |= 1;
            }
            if (!f)
                return false;
        }
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int l = 0, r = 1e9 + 10, mid;
        sort(heaters.begin(), heaters.end());
        while (l < r) {
            mid = (l + r) / 2;
            if (ck(houses, heaters, mid)) {
                r = mid;
            } else
                l = mid + 1;
        }
        return r;
    }
};