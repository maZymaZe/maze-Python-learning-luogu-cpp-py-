class Solution {
   public:
    char kthCharacter(int k) {
        int a = 1, b = 2;
        if (k == 1)
            return 'a';
        while (b < k) {
            a *= 2;
            b *= 2;
        }
        return (kthCharacter(k - a) - 'a' + 1) % 26 + 'a';
    }
};