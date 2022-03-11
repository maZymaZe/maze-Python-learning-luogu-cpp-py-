class Solution {
   public:
    vector<int> numMovesStones(int a, int b, int c) {
        int d[3] = {a, b, c};
        sort(d, d + 3);
        int ma, mi;
        if (d[0] == d[1] - 1 && d[1] == d[2] - 1)
            mi = 0;
        else if (d[0] == d[1] - 1 || d[1] == d[2] - 1) {
            mi = 1;
        } else if (d[0] == d[1] - 2 || d[1] == d[2] - 2)
            mi = 1;
        else
            mi = 2;
        return {mi, d[2] - d[0] - 2};
    }
};