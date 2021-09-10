class Solution {
   public:
    bool validUtf8(vector<int>& data) {
        int l = data.size(), p = 0;
        while (p < l) {
            if ((data[p] & 0x80) == 0)
                p++;
            else if (((data[p] >> 5) & 7) == 6) {
                if (p + 1 >= l)
                    return false;
                for (int i = 1; i <= 1; i++) {
                    if (((data[p + i] >> 6) & 3) != 2)
                        return false;
                }
                p += 2;
            } else if (((data[p] >> 4) & 15) == 14) {
                if (p + 2 >= l)
                    return false;
                for (int i = 1; i <= 2; i++) {
                    if (((data[p + i] >> 6) & 3) != 2)
                        return false;
                }
                p += 3;
            } else if (((data[p] >> 3) & 31) == 30) {
                if (p + 3 >= l)
                    return false;
                for (int i = 1; i <= 3; i++) {
                    if (((data[p + i] >> 6) & 3) != 2)
                        return false;
                }
                p += 4;
            } else
                return false;
        }
        if (p == l)
            return true;
        return false;
    }
};