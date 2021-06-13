class Solution {
   public:
    int threeSumMulti(vector<int>& arr, int target) {
        typedef long long ll;
        ll c[302] = {0};
        ll ans = 0, MOD = 1e9 + 7, l = arr.size();
        for (int i = 0; i < l; i++)
            c[arr[i]]++;
        for (int i = 0; i <= 100; i++) {
            for (int j = i; j <= 100; j++) {
                if (target - i - j < j)
                    continue;
                if (i == j && target == i + i + i) {
                    if (c[i] < 3)
                        continue;
                    (ans += c[i] * (c[i] - 1) * (c[i] - 2) / 6) %= MOD;
                } else if (i == j) {
                    if (c[i] < 2)
                        continue;
                    (ans += c[i] * (c[i] - 1) * (c[target - i - i]) / 2) %= MOD;
                } else if (j == target - i - j) {
                    if (c[j] < 2)
                        continue;
                    (ans += c[j] * (c[j] - 1) * (c[i]) / 2) %= MOD;
                } else {
                    (ans += c[j] * (c[i]) * (c[target - i - j])) %= MOD;
                }
            }
        }
        return ans;
    }
};