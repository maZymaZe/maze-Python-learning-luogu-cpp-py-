class Solution {
   public:
    bool isRobotBounded(string instructions) {
        instructions = instructions + instructions;
        instructions = instructions + instructions;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, x = 0, y = 0, d = 0;
        for (auto c : instructions) {
            if (c == 'G')
                x += dx[d], y += dy[d];
            if (c == 'L')
                d = (d + 3) % 4;
            if (c == 'R')
                d = (d + 1) % 4;
        }
        return x == 0 && y == 0 && d == 0;
    }
};