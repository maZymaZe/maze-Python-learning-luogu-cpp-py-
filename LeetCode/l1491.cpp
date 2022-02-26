class Solution {
   public:
    double average(vector<int>& salary) {
        int mi = 0x3f3f3f3f, ma = -1, tot = 0;
        for (int i : salary) {
            mi = min(mi, i), ma = max(ma, i), tot += i;
        }
        return 1.0 * (tot - mi - ma) / (salary.size() - 2);
    }
};