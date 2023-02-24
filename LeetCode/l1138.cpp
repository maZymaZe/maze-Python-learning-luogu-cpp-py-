class Solution {
   public:
    string alphabetBoardPath(string target) {
        int cx = 0, cy = 0;
        string res;
        for (char c : target) {
            int nx = (c - 'a') / 5;
            int ny = (c - 'a') % 5;
            if (nx < cx) {
                res.append(cx - nx, 'U');
            }
            if (ny < cy) {
                res.append(cy - ny, 'L');
            }
            if (nx > cx) {
                res.append(nx - cx, 'D');
            }
            if (ny > cy) {
                res.append(ny - cy, 'R');
            }
            res.push_back('!');
            cx = nx;
            cy = ny;
        }
        return res;
    }
};
