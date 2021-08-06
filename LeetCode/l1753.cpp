class Solution {
   public:
    int maximumScore(int a, int b, int c) {
        if (a > b)
            swap(a, b);
        if (b > c)
            swap(b, c);
        if (a > b)
            swap(a, b);
        if (c >= a + b)
            return a + b;
        return (a + b + c) / 2;
    }
};