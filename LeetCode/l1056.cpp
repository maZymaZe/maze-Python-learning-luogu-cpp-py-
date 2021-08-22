class Solution {
   public:
    bool confusingNumber(int n) {
        int dg[30] = {0}, d = 0;
        while (n) {
            dg[++d] = n % 10;
            n /= 10;
        }
        for (int i = 1; i <= d; i++) {
            if (dg[i] == 2 || dg[i] == 3 || dg[i] == 4 || dg[i] == 5 ||
                dg[i] == 7)
                return false;
        }
        if (dg[1] == '0')
            return false;
        int op[30] = {0};
        op[0] = 0, op[1] = 1, op[6] = 9, op[9] = 6, op[8] = 8;
        for (int i = 1; i <= d; i++) {
            if (op[dg[i]] != dg[d - i + 1])
                return true;
        }
        return false;
    }
};