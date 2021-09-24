class Solution {
   public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;
        int d = pow(10, n - 1), u = pow(10, n) - 1;
        for (int i = u; i >= d; i--) {
            string t = to_string(i);
            string rev = t;
            reverse(rev.begin(), rev.end());
            string add = t + rev;
            long long addNum = stoll(add);
            for (long long j = u; j * j >= addNum; j--) {
                if (addNum % j == 0)
                    return addNum % 1337;
            }
        }
        return -1;
    }
};