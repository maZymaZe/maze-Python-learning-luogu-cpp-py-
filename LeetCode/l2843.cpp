class Solution {
   public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            int n = s.length();
            if (n % 2 == 0) {
                int sum[2] = {0};
                for (int j = 0; j < n / 2; j++) {
                    sum[0] += s[j] - '0';
                    sum[1] += s[n - j - 1] - '0';
                }
                ans += sum[0] == sum[1];
            }
        }
        return ans;
    }
};