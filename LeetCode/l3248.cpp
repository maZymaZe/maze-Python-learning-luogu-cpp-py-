class Solution {
   public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0, y = 0;
        for (const auto& c : commands) {
            if (c[0] == 'U')
                x--;
            if (c[0] == 'D')
                x++;
            if (c[0] == 'L')
                y--;
            if (c[0] == 'R')
                y++;
        }
        return x * n + y;
    }
};