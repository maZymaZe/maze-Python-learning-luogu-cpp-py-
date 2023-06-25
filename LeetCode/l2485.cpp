class Solution {
   public:
    int pivotInteger(int n) {
        int t = n * (n + 1) / 2;
        int u = sqrt(t);
        if (u * u == t)
            return u;
        return -1;
    }
};