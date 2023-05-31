class Solution {
   public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int l = 0, r = 1e9 + 2;
        int mid;
        while (l < r) {
            mid = (r + l + 1) / 2;
            int b = price[0], ok = 1;
            for (int i = 0; i < k - 1; i++) {
                auto it = lower_bound(price.begin(), price.end(), b + mid);
                if (it == price.end()) {
                    ok = 0;
                    break;
                }
                b = *it;
            }
            if (ok) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};