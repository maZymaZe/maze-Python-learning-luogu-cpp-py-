class Solution {
   public:
    int cal(const vector<int>& x) {
        int tot = 0, l = x.size();
        for (int i = 0; i < l; i++) {
            if ((i > 0 && x[i - 1] == 10) || (i > 1 && x[i - 2] == 10))
                tot += 2 * x[i];
            else
                tot += x[i];
        }
        return tot;
    }
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int v1 = cal(player1), v2 = cal(player2);
        if (v1 > v2)
            return 1;
        else if (v1 < v2)
            return 2;
        return 0;
    }
};