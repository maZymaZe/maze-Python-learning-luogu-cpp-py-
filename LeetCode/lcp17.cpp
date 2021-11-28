class Solution {
   public:
    int calculate(string s) {
        int x = 1, y = 0;
        for (char i : s) {
            if (i == 'A')
                x = 2 * x + y;
            else
                y = 2 * y + x;
        }
        return x + y;
    }
};