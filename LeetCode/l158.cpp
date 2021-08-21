/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
   public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char bf[10];
    int bbf = 0;
    int read(char* buf, int n) {
        int c = 0, rr = 0;
        if (bbf >= n) {
            for (int i = 0; i < n; i++) {
                buf[rr + i] = bf[i];
            }
            c += n;
            rr += n;
            for (int i = n; i < bbf; i++) {
                bf[i - n] = bf[i];
            }
            bbf -= n;
            return c;
        } else if (bbf) {
            for (int i = 0; i < bbf; i++) {
                buf[rr + i] = bf[i];
            }
            c += bbf;
            rr += bbf;
            bbf = 0;
        }

        while (1) {
            int r = read4(bf);
            c += r;
            if (c > n) {
                int nd = n - rr;
                for (int i = 0; i < nd; i++) {
                    buf[rr + i] = bf[i];
                }
                for (int i = nd; i < r; i++) {
                    bf[i - nd] = bf[i];
                }
                bbf = r - nd;
                rr += nd;
                c = n;
                return c;
            } else {
                for (int i = 0; i < r; i++) {
                    buf[rr + i] = bf[i];
                }
                rr += r;
            }
            if (c == n)
                break;
            if (r == 0)
                break;
        }
        return c;
    }
};