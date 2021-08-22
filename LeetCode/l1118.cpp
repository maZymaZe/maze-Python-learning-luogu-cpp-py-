int ck(int x) {
    if (x % 400 == 0)
        return 1;
    if (x % 100 == 0)
        return 0;
    if (x % 4 == 0)
        return 1;
    return 0;
}
class Solution {
   public:
    int numberOfDays(int year, int month) {
        int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month != 2) {
            return days[month];
        }
        return 28 + ck(year);
    }
};