#include <algorithm>
using namespace std;
class Solution {
   public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = n * m + 1, mid;
        while (l + 1 < r) {
            int tot = 0, mito = 0, ma;
            mid = (l + r) / 2;
            ma = 0;
            for (int i = 1; i <= n; i++) {
                tot += min(m, mid / i);
                mito += min(m, (mid - 1) / i);
                ma = max(ma, min(m, mid / i) * i);
            }
            if (k > mito && k <= tot)
                return ma;
            if (k > tot)
                l = mid;
            else
                r = mid;
        }
        return -1;
    }
};
int main() {
    Solution().findKthNumber(21, 36, 623);
    return 0;
}