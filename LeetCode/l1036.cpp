class Solution {
   public:
    long long hs(int x, int y) { return (long long)x * 1000000 + y; }
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, n = 1000000, lim = 41000;
    bool isEscapePossible(vector<vector<int>>& blocked,
                          vector<int>& source,
                          vector<int>& target) {
        int cnt = 0;
        if (target[0] == source[0] && target[1] == source[1])
            return true;
        queue<int> xx, yy;
        xx.push(source[0]), yy.push(source[1]);
        unordered_set<long long> s, b;
        int l = blocked.size();
        for (int i = 0; i < l; i++) {
            b.insert(hs(blocked[i][0], blocked[i][1]));
        }
        s.insert(hs(source[0], source[1]));
        while (!xx.empty()) {
            int tx = xx.front(), ty = yy.front();
            xx.pop(), yy.pop();
            cnt++;
            for (int i = 0; i < 4; i++) {
                int nx = tx + dx[i], ny = ty + dy[i];
                long long h = hs(nx, ny);
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !s.count(h) &&
                    !b.count(h)) {
                    if (nx == target[0] && ny == target[1])
                        return true;
                    xx.push(nx);
                    yy.push(ny);
                    s.insert(h);
                }
            }
            if (cnt >= lim)
                break;
        }
        if (cnt < lim)
            return false;
        cnt = 0;
        s.clear();
        s.insert(hs(target[0], target[1]));
        queue<int> xxx, yyy;
        xxx.push(target[0]), yyy.push(target[1]);
        while (!xxx.empty()) {
            int tx = xxx.front(), ty = yyy.front();
            xxx.pop(), yyy.pop();
            cnt++;
            for (int i = 0; i < 4; i++) {
                int nx = tx + dx[i], ny = ty + dy[i];
                long long h = hs(nx, ny);
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !s.count(h) &&
                    !b.count(h)) {
                    if (nx == source[0] && ny == source[1])
                        return true;
                    xxx.push(nx);
                    yyy.push(ny);
                    s.insert(h);
                }
            }
            if (cnt >= lim)
                break;
        }
        if (cnt < lim)
            return false;
        return true;
    }
};