class Solution {
public:
 int rangeBitwiseAnd(int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (m > n)
        return rangeBitwiseAnd(n, m);
    long long p = 1;
    while (p <= n)
        p <<= 1;
    p >>= 1;
    if (p <= m)
        return rangeBitwiseAnd(m ^ p, n ^ p) | p;
    return 0;
    }
};