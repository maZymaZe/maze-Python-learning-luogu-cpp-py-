class Solution {
   public:
    int gnm(int n, int mx) {
        int ans = 1;
        long long l = (long long)n * 10 + 0;
        long long r = (long long)n * 10 + 9;
        while (mx >= l) {
            if (mx <= r)
                ans += (mx - l + 1);
            else
                ans += (r - l + 1);
            l = l * 10 + 0;
            r = r * 10 + 9;
        }
        return ans;
    }
    int findKthNumber(int n, int k) {
        int l = 1, r = 9;
        while (k) {
            for (int i = l; i <= r; i++) {
                int f = gnm(i, n);
                if (k > f) {
                    k -= f;
                } else {
                    k--;
                    if (k == 0)
                        return i;
                    l = i * 10 + 0;
                    r = i * 10 + 9;
                    break;
                }
            }
        }

        return 0;
    }
};