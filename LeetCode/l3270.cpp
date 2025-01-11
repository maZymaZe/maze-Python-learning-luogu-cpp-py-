class Solution {
   public:
    int generateKey(int num1, int num2, int num3) {
        int t[4] = {0};
        t[0] = min({num1 / 1000, num2 / 1000, num3 / 1000}) * 1000;
        num1 %= 1000, num2 %= 1000, num3 %= 1000;
        t[1] = min({num1 / 100, num2 / 100, num3 / 100}) * 100;
        num1 %= 100, num2 %= 100, num3 %= 100;
        t[2] = min({num1 / 10, num2 / 10, num3 / 10}) * 10;
        num1 %= 10, num2 %= 10, num3 %= 10;
        t[3] = min({num1, num2, num3});
        int ans = 0;
        for (int i = 0; i < 4; i++)
            ans += t[i];
        return ans;
    }
};