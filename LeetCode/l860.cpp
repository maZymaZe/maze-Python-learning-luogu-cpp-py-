class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0;
        for (int i : bills) {
            if (i == 5)
                c5++;
            else if (i == 10) {
                if (c5 == 0)
                    return false;
                else {
                    c5--;
                    c10++;
                }
            } else {
                if (c5 && c10) {
                    c5--, c10--;
                } else if (c5 >= 3)
                    c5 -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};