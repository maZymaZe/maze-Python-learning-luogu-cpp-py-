class Solution {
   public:
    string tictactoe(vector<vector<int>>& moves) {
        int l = moves.size();
        int mp[3][3] = {0};
        for (int i = 0; i < l; i++) {
            mp[moves[i][0]][moves[i][1]] = (i & 1) + 1;
        }
        for (int i = 0; i < 3; i++) {
            if (mp[0][i] == 1 && mp[1][i] == 1 && mp[2][i] == 1)
                return "A";
            if (mp[i][0] == 1 && mp[i][1] == 1 && mp[i][2] == 1)
                return "A";
        }
        if (mp[1][1] == 1 && mp[0][0] == 1 && mp[2][2] == 1)
            return "A";
        if (mp[0][2] == 1 && mp[1][1] == 1 && mp[2][0] == 1)
            return "A";

        for (int i = 0; i < 3; i++) {
            if (mp[0][i] == 2 && mp[1][i] == 2 && mp[2][i] == 2)
                return "B";
            if (mp[i][0] == 2 && mp[i][1] == 2 && mp[i][2] == 2)
                return "B";
        }
        if (mp[1][1] == 2 && mp[0][0] == 2 && mp[2][2] == 2)
            return "B";
        if (mp[0][2] == 2 && mp[1][1] == 2 && mp[2][0] == 2)
            return "B";
        if (l == 9)
            return "Draw";
        return "Pending";
    }
};