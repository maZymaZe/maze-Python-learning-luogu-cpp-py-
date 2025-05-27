class Solution {
   public:
    int differenceOfSums(int n, int m) {
        return n * (n + 1) / 2 - (n / m) * (n / m * m + m);
    }
};