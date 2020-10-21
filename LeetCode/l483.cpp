class Solution {
   public:
    string smallestGoodBase(string n) {
        long long m = stol(n);
        long long ans = m - 1;
        for (int s = 59; s > 1; s--) {
            int k = pow(m, 1.0 / s);
            if (k > 1) {
                long long sum = 1, mul = 1;
                for (int i = 1; i <= s; i++) {
                    mul *= k;
                    sum += mul;
                }
                if (sum == m) {
                    ans = k;
                    break;
                }
            }
        }
        return to_string(ans);
    }
};