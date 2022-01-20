class Solution {
   public:
    bool stoneGameIX(vector<int>& stones) {
        int c[3] = {0};
        for (int i : stones)
            c[i % 3]++;
        if ((c[0] & 1) == 0)
            return c[1] >= 1 && c[2] >= 1;
        return c[1] - c[2] > 2 || c[2] - c[1] > 2;
    }
};