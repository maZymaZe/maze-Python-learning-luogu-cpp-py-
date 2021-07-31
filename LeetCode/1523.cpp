class Solution {
   public:
    int countOdds(int low, int high) {
        if ((low & 1) && (high & 1))
            high++;
        else if (!(low & 1) && !(high & 1))
            low++;
        if (low > high)
            return 0;
        return (high - low + 1) / 2;
    }
};