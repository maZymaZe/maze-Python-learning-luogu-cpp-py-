class Solution {
   public:
    int minSwaps(string s) {
        int ma = 0, x = 0;
        for (char c : s) {
            if (c == ']')
                x++;
            else
                x--;
            ma = max(ma, x);
        }
        return (ma + 1) / 2;
    }
};