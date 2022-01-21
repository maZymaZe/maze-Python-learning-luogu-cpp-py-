class Solution {
   public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> ans(length);
        int gs = w / 32;
        int bg = y * gs;
        for (int i = 0; i < gs; i++) {
            int bb = i * 32, ee = i * 32 + 31;
            if (bb > x2 || ee < x1)
                continue;
            bb = max(bb, x1), ee = min(ee, x2);
            long long x = 0;
            x |= ((1ll << (ee % 32 + 1)) - 1);
            x ^= ((1ll << (bb % 32)) - 1);
            long long yy = 0, t;
            for (int j = 0; j < 32; j++) {
                t = x;
                yy |= ((t >> j) & 1) << (32 - j - 1);
            }
            ans[i + bg] = yy;
        }
        return ans;
    }
};