class Solution {
   public:
    long long repairCars(vector<int>& ranks, int cars) {
        int c[120] = {0};
        for (int i : ranks)
            c[i]++;
        long long l = 0, r = 1ll << 60;
        while (l < r) {
            long long mid = (l + r) / 2, tot = 0;
            for (int i = 1; i <= 100; i++) {
                tot += (long long)(sqrt(mid / i)) * c[i];
            }
            if (tot < cars) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};