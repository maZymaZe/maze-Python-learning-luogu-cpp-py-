class Solution {
   public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        unsigned int x;
        int flag = 1;
        if (num < 0) {
            if (num == 0x80000000)
                return "80000000";
            flag = -1;
            x = -num;
            x = (~x) + 1;
        } else
            x = num;
        int d[20] = {0};
        for (int i = 0; i < 8; i++) {
            d[i] = x & 0xf;
            x >>= 4;
        }
        string ans;
        int ff = 0;
        for (int i = 7; i >= 0; i--) {
            if (ff == 0 && d[i] == 0)
                continue;
            else {
                ff = 1;
                if (d[i] < 10)
                    ans += (char)(d[i] + '0');
                else
                    ans += (char)(d[i] + 'a' - 10);
            }
        }
        return ans;
    }
};