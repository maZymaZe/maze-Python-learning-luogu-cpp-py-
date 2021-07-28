class Solution {
   public:
    int reachNumber(int target) {
        target = abs(target);
        long long t = sqrt(2 * target);
        while (1) {
            long long rs = (1 + t) * t / 2;
            if (rs > target && (rs - target) % 2 == 0)
                return t;
            t++;
        }
        return -1;
    }
};