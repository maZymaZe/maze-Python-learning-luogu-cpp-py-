class Solution {
   public:
    string categorizeBox(int length, int width, int height, int mass) {
        int m = 0, h = (mass >= 100);
        if (length >= 10000 || width >= 10000 || height >= 10000)
            m |= 1;
        long long x = 1;
        x *= length;
        x *= width;
        x *= height;
        if (x >= 1000000000)
            m |= 1;
        if (m && h)
            return "Both";
        if (h)
            return "Heavy";
        if (m)
            return "Bulky";
        return "Neither";
    }
};