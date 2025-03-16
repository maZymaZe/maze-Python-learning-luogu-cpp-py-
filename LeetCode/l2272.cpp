class Solution {
   public:
    int largestVariance(string s) {
        int ans = 0;
        for (char a = 'a'; a <= 'z'; a++) {
            for (char b = 'a'; b <= 'z'; b++) {
                if (b == a) {
                    continue;
                }
                int f0 = 0, f1 = INT_MIN;
                for (char ch : s) {
                    if (ch == a) {
                        f0 = max(f0, 0) + 1;
                        f1++;
                    } else if (ch == b) {
                        f1 = f0 = max(f0, 0) - 1;
                    }  // else f0 = max(f0, 0); 可以留到 ch 等于 a 或者 b
                       // 的时候计算，f1 不变
                    ans = max(ans, f1);
                }
            }
        }
        return ans;
    }
};
