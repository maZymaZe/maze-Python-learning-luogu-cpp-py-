class Solution {
   public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int x = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(x));
    }
};