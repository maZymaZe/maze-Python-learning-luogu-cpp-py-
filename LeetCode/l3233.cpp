class Solution {
   public:
    int nonSpecialCount(int l, int r) {
        int isp[100000] = {0};
        for (int i = 2; (long long)i * i <= r; i++) {
            if (isp[i] == 0) {
                isp[i] = 1;
                for (int j = 2 * i; (long long)j * j <= r; j += i) {
                    isp[j] = 2;
                }
            }
        }
        int ans = r - l + 1;
        for (int i = 2; i * i <= r; i++) {
            if (isp[i] == 1 && (long long)i * i >= l && (long long)i * i <= r)
                ans--;
        }
        return ans;
    }
};