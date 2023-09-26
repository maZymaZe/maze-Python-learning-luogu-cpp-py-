class Solution {
   public:
    int passThePillow(int n, int time) {
        if (n == 1)
            return 1;
        time = (time + 2 * n - 2) % (2 * n - 2) + 1;
        if (time <= n)
            return time;
        return n - (time - n);
    }
};