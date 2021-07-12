class Solution {
   public:
    int maxProfit(vector<int>& inventory, int orders) {
        inventory.push_back(0);
        const long long MOD = 1e9 + 7;
        sort(inventory.begin(), inventory.end());
        long long ans = 0, l = inventory.size();
        int p = l - 1;
        while (p > 0) {
            if (inventory[p] > inventory[p - 1]) {
                int ma = (l - p) * (inventory[p] - inventory[p - 1]);
                if (ma <= orders) {
                    (ans += (long long)(inventory[p] + inventory[p - 1] + 1) *
                            (inventory[p] - inventory[p - 1]) / 2 * (l - p)) %=
                        MOD;
                    if (ma == orders)
                        return ans;
                    else
                        orders -= ma;
                } else {
                    int t = orders / (l - p);
                    int r = orders % (l - p);
                    (ans += (long long)(inventory[p] + inventory[p] - t + 1) *
                            (t) / 2 * (l - p)) %= MOD;
                    (ans += (long long)(inventory[p] - t) * r) %= MOD;
                    return ans;
                }
            }
            p--;
        }
        return -1;
    }
};