class Solution {
   public:
    string similarRGB(string color) {
        string ans(7, '*');
        ans[0] = '#';
        for (int i = 1; i <= 3; i++) {
            int a = color[i * 2 - 1], b = color[i * 2];
            if (a >= '0' && a <= '9')
                a -= '0';
            else
                a -= 'a' - 10;
            if (b >= '0' && b <= '9')
                b -= '0';
            else
                b -= 'a' - 10;
            int tot = a * 16 + b;
            int mi = 9999, mip;
            for (int j = 0; j <= 15; j++) {
                if (abs(tot - j * 17) < mi)
                    mi = abs(tot - j * 17), mip = j;
            }
            if (mip < 10)
                ans[i * 2 - 1] = ans[i * 2] = '0' + mip;
            else
                ans[i * 2 - 1] = ans[i * 2] = 'a' + mip - 10;
        }
        return ans;
    }
};