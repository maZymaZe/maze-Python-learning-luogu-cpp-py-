class Solution {
   public:
    int mp[17000][15] = {0};
    int sz[17000];
    int rs[17000];
    int gd[15][15] = {0};
    int v[17000] = {0};
    int l;
    vector<int> nb;
    void dfs(int x) {
        if (v[x])
            return;
        v[x] = 1;
        vector<int> cd;
        for (int i = 0; i < l; i++) {
            if (x & (1 << i))
                cd.push_back(i), sz[x]++;
        }
        rs[x] = -0x3f3f3f3f;
        int len = cd.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int nx = x - (1 << (cd[i])) - (1 << (cd[j]));
                dfs(nx);
                int tgcd = gd[cd[i]][cd[j]];
                int ps = sz[x] / 2, pp = 1, tot = 0;
                for (int k = 1; k <= ps; k++) {
                    if (tgcd < mp[nx][pp] || pp == ps) {
                        tot += tgcd * k;
                    } else
                        tot += mp[nx][pp++] * k;
                }
                pp = 1;
                if (tot > rs[x]) {
                    for (int k = 1; k <= ps; k++) {
                        if (tgcd < mp[nx][pp] || pp == ps) {
                            mp[x][k] = tgcd;
                        } else
                            mp[x][k] = mp[nx][pp++];
                    }
                    rs[x]=tot;
                }
            }
        }
    }
    int maxScore(vector<int>& nums) {
        l = nums.size();
        nb = nums;
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                gd[i][j] = __gcd(nums[i], nums[j]);
            }
        }
        v[0] = 1;
        rs[0] = 0;
        dfs((1 << l) - 1);
        return rs[(1 << l) - 1];
    }
};