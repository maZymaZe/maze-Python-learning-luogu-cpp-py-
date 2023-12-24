class Solution {
   public:
    long long minimumPerimeter(long long neededApples) {
        long long l = 1, r = 1e5;
        long long mid;
        while (l < r) {
            mid = (l + r) / 2;
            if ((4 * mid + 2) * (1 + mid) * mid < neededApples) {
                l = mid + 1;
            } else
                r = mid;
        }
        return r * 8;
    }
};