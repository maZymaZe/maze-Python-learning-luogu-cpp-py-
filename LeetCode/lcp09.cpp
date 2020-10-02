struct pr {
    int pos, stp;
};
class Solution {
   public:
    int n, ml = 0;
    int minJump(vector<int>& jump) {
        n = jump.size();
        int vis[1000007] = {0};
        pr q[1000007] = {{0, 0}};
        int head = 0, tail = 0;
        vis[0] = 1;
        while (head <= tail) {
            pr now = q[head];
            head++;
            int t = now.pos + jump[now.pos];
            if (t >= n)
                return now.stp + 1;
            if (!vis[t])
                q[++tail] = {t, now.stp + 1};
            vis[t] = 1;
            for (int i = now.pos - 1; i > ml; i--) {
                if (!vis[i]) {
                    q[++tail] = {i, now.stp + 1};
                    vis[i] = 1;
                }
            }
            ml = now.pos;
        }
        return 0;
    }
};