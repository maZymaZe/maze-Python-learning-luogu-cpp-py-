class Solution {
   public:
    int mirrorReflection(int p, int q) {
        int isup = 1;

        int lp = 0, rp = q;
        if (rp == 0)
            return 0;
        if (rp == p)
            return 1;
        while (1) {
            if (rp + q * isup <= p && rp + q * isup >= 0) {
                lp = rp + q * isup;
            } else if (rp + q * isup > p) {
                lp = 2 * p - rp - q * isup;
                isup *= -1;
            } else if (rp + q * isup < 0) {
                lp = -(rp + q * isup);
                isup *= -1;
            }
            if (lp == p)
                return 2;
            if (lp + q * isup <= p && lp + q * isup >= 0) {
                rp = lp + q * isup;
            } else if (lp + q * isup > p) {
                rp = 2 * p - lp - q * isup;
                isup *= -1;
            } else if (lp + q * isup < 0) {
                rp = -(lp + q * isup);
                isup *= -1;
            }
            if (rp == 0)
                return 0;
            if (rp == p)
                return 1;
        }
        return 0;
    }
};