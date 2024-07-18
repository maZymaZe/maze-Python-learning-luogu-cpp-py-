class Solution {
   public:
    int minimumLevels(vector<int>& possible) {
        int l = possible.size();
        int t1 = possible[0] * 2 - 1, t2 = 0;
        for (int i = 1; i < l; i++) {
            t2 += (possible[i] * 2) - 1;
        }
        if (t1 > t2)
            return 1;
        for (int i = 1; i < l - 1; i++) {
            t1 += 2 * (possible[i] * 2 - 1);
            if (t1 > t2)
                return 1 + i;
        }
        return -1;
    }
};