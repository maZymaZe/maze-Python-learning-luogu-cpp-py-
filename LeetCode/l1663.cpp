class Solution {
   public:
    string getSmallestString(int n, int k) {
        int l1, l2 = 1, l3;
        k -= n;
        l3 = k / 25;
        if (l3 == n)
            return string(n, 'z');
        return string(n - l2 - l3, 'a') + string(1, k % 25 + 'a') +
               string(l3, 'z');
    }
};