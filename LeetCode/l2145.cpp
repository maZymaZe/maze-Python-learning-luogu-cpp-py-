class Solution {
   public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mi = 0, ma = 0, cur = 0;
        for (int i : differences) {
            cur += i;
            mi = min(mi, cur);
            ma = max(ma, cur);
        }
        return max(0ll, upper - lower + 1 - (ma - mi));
    }
};