class Solution {
   public:
    int reinitializePermutation(int n) {
        int s = n - 2, c = 0;
        do {
            if (s % 2 == 0)
                s /= 2;
            else
                s = n / 2 + s / 2;
            c++;
        } while (s != n - 2);
        return c;
    }
};