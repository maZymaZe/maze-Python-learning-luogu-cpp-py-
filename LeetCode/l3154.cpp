class Solution {
   public:
    int C(int a, int b) {
        b = min(b, a - b);
        long long tot = 1;
        for (int i = 0; i < b; i++) {
            tot *= (a - i);
            tot /= (i + 1);
        }
        return tot;
    }
    int waysToReachStair(int k) {
        int ans = 0;
        int tot = 1, p = 1;
        for (int i = 0;; i++) {
            if (tot == k) {
                ans++;
            } else if (tot > k) {
                int x = i + 1, y = tot - k;
                if (x >= y)
                    ans += C(x, y);
                else
                    break;
            }
            tot += p;
            p *= 2;
        }
        return ans;
    }
};