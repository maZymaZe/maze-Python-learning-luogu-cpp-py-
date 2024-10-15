class Solution {
   public:
    int maxHeightOfTriangle(int red, int blue) {
        int c[2] = {red, blue};
        int ans1 = 0, ans2 = 0;
        for (int i = 1; i < 100; i++) {
            if (c[i % 2] >= i)
                c[i % 2] -= i;
            else {
                ans1 = i - 1;
                break;
            }
        }
        c[0] = blue, c[1] = red;
        for (int i = 1; i < 100; i++) {
            if (c[i % 2] >= i)
                c[i % 2] -= i;
            else {
                ans2 = i - 1;
                break;
            }
        }
        return max(ans1, ans2);
    }
};