class Solution {
   public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0, t;
        t = min(k, numOnes);
        ans += t, k -= t;
        t = min(k, numZeros);
        k -= t;
        t = min(k, numNegOnes);
        ans -= t, k -= t;
        return ans;
    }
};