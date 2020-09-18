class Solution {
   public:
    int exchangeBits(int num) {
        int mask = 0x55555555;
        int a = num & mask, b = num & (~mask);
        return (a << 1) | (b >> 1);
    }
};