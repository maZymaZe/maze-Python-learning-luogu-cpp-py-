class Solution {
   public:
    long long cal(long long x, long long y) {
        int os = max(0ll, y - x);
        y = min(y, x);
        return (x + x - y + 1) * y / 2 + os;
    }
    int maxValue(int n, int index, int maxSum) {
        int mid, l = 0, r = 1e9 + 7;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            long long sum = cal(mid, index + 1) + cal(mid, n - index) - mid;
            if (sum <= maxSum)
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};