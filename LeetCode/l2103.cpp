class Solution {
   public:
    static constexpr int POLE_NUM = 10;
    static constexpr int COLOR_NUM = 3;
    int getColorId(char color) {
        if (color == 'R') {
            return 0;
        } else if (color == 'G') {
            return 1;
        }
        return 2;
    }
    int countPoints(string rings) {
        vector<vector<int>> state(POLE_NUM, vector<int>(COLOR_NUM, 0));
        int n = rings.size();
        for (int i = 0; i < n; i += 2) {
            char color = rings[i];
            int pole_index = rings[i + 1] - '0';
            state[pole_index][getColorId(color)] = 1;
        }
        int res = 0;
        for (int i = 0; i < POLE_NUM; i++) {
            bool flag = true;
            for (int j = 0; j < COLOR_NUM; j++) {
                if (state[i][j] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res++;
            }
        }
        return res;
    }
};
