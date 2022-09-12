class Solution {
   public:
    int add(int a, int b) {
        return b == 0 ? a : add(a ^ b, (unsigned int)(a & b) << 1);
    }
};