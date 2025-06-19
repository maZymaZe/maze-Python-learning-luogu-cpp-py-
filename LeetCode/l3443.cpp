class Solution {
   public:
    int maxDistance(string s, int k) {
        int l = s.size(), ans = 0;
        int x = 0, y = 0, c[4] = {0};
        for (int i = 0; i < l; i++) {
            if (s[i] == 'N') {
                x--;
                c[0]++;
            } else if (s[i] == 'S') {
                x++;
                c[1]++;
            } else if (s[i] == 'E') {
                y++;
                c[2]++;
            } else if (s[i] == 'W') {
                y--;
                c[3]++;
            }
            int dx = (x > 0) ? c[0] : c[1], dy = (y > 0) ? c[3] : c[2];
            ans = max(ans, abs(x) + abs(y) + 2 * min(k, dx + dy));
        }
        return ans;
    }
};