class Solution {
   public:
    int hs(int x, int y) { return x * 1005 + y; }
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int dx = 0, dy = 0, cl = command.size(), ol = obstacles.size();
        unordered_map<int, int> mp;
        mp[0] = 0;
        for (int i = 0; i < cl; i++) {
            if (command[i] == 'U')
                dy++;
            else
                dx++;
            mp[hs(dx, dy)] = i + 1;
        }
        if (dx == 0) {
            if (x)
                return false;
            for (int i = 0; i < ol; i++) {
                if (obstacles[i][0] == 0 && obstacles[i][1] < y)
                    return false;
            }
            return true;
        } else if (dy == 0) {
            if (y)
                return false;
            for (int i = 0; i < ol; i++) {
                if (obstacles[i][1] == 0 && obstacles[i][0] < x)
                    return false;
            }
            return true;
        }
        int a = min(x / dx, y / dy);
        int ttx = x - a * dx, tty = y - a * dy;
        if (!mp.count(hs(ttx, tty)))
            return false;
        int b = mp[hs(ttx, tty)];
        for (int i = 0; i < ol; i++) {
            int oa = min(obstacles[i][0] / dx, obstacles[i][1] / dy);
            int otx = obstacles[i][0] - oa * dx,
                oty = obstacles[i][1] - oa * dy;
            if (!mp.count(hs(otx, oty)))
                continue;
            int ob = mp[hs(otx, oty)];
            if (oa < a || (oa == a && ob < b))
                return false;
        }
        return true;
    }
};