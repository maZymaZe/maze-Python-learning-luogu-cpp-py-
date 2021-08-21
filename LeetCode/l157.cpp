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
    int read(char* buf, int n) {
        int c = 0;
        while (1) {
            int r = read4(buf + c);
            c += r;
            if (c > n) {
                buf[n] = 0;
                c = n;
                break;
            }
            if (r == 0)
                break;
        }
        return c;
    }
};