int n, m;
struct pt {
    int x, y;
};
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
vector<vector<int> > bfs(int x, int y, vector<vector<int> >& mp) {
    vector<vector<int> > ret(n + 2, vector<int>(m + 2, -1));
    ret[x][y] = 0;
    queue<pt> q;
    q.push({x, y});
    while (!q.empty()) {
        pt tt = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = tt.x + dx[i], ny = tt.y + dy[i];
            if (mp[nx][ny] != -1 && ret[nx][ny] == -1) {
                ret[nx][ny] = ret[tt.x][tt.y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return ret;
}
class Solution {
public:
    int minimalSteps(vector<string>& maze) {
        int sx, sy, tx, ty;
        n = maze.size(), m = maze[0].size();
        vector<vector<int> > mp(n + 2, vector<int>(m + 2, -1));
        vector<pt> bt, st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'S') {
                    sx = i + 1, sy = j + 1;
                } else if (maze[i][j] == 'T') {
                    tx = i + 1, ty = j + 1;
                } else if (maze[i][j] == 'M') {
                    bt.push_back({i + 1, j + 1});
                } else if (maze[i][j] == 'O') {
                    st.push_back({i + 1, j + 1});
                }
                if (maze[i][j] != '#')
                    mp[i + 1][j + 1] = 0;
            }
        }
        int nb = bt.size(), ns = st.size();
        vector<vector<int> > sdis = bfs(sx, sy, mp);
        if (nb == 0)
            return sdis[tx][ty];
        vector<vector<int> > dis(nb, vector<int>(nb + 2, -1));

        vector<vector<vector<int> > > dd(nb);
        for (int i = 0; i < nb; i++) {
            dd[i] = bfs(bt[i].x, bt[i].y, mp);
            dis[i][nb + 1] = dd[i][tx][ty];
        }

        for (int i = 0; i < nb; i++) {
            int tmp = -1;
            for (int k = 0; k < ns; k++) {
                int mx = st[k].x, my = st[k].y;
                if (dd[i][mx][my] != -1 && sdis[mx][my] != -1) {
                    if (tmp == -1 || tmp > dd[i][mx][my] + sdis[mx][my]) {
                        tmp = dd[i][mx][my] + sdis[mx][my];
                    }
                }
            }
            dis[i][nb] = tmp;
            for (int j = i + 1; j < nb; j++) {
                int mn = -1;
                for (int k = 0; k < ns; k++) {
                    int mx = st[k].x, my = st[k].y;
                    if (dd[i][mx][my] != -1 && dd[j][mx][my] != -1) {
                        if (mn == -1 || mn > dd[i][mx][my] + dd[j][mx][my]) {
                            mn = dd[i][mx][my] + dd[j][mx][my];
                        }
                    }
                }
                dis[i][j] = dis[j][i] = mn;
            }
        }
        for (int i = 0; i < nb; i++) {
            if (dis[i][nb] == -1 || dis[i][nb + 1] == -1)
                return -1;
        }
        vector<vector<int> > dp(1 << nb, vector<int>(nb, -1));
        for (int i = 0; i < nb; i++) {
            dp[1<<i][i]=dis[i][nb];
        }
        for(int mask=1;mask<(1<<nb);mask++) {
            for(int i=0;i<nb;i++) {
                if(mask&(1<<i)){
                    for(int j=0;j<nb;j++){
                        if(!(mask&(1<<j))){
                            int nxt=mask|(1<<j);
                            if(dp[nxt][j]==-1||dp[nxt][j]>dp[mask][i]+dis[i][j]){
                                dp[nxt][j]=dp[mask][i]+dis[i][j];
                            }
                        }
                    }
                }
            }
        }
        int ret=-1,fm=(1<<nb)-1;
        for(int i=0;i< nb; i++){
            if(ret==-1||ret>dp[fm][i]+dis[i][nb+1]){
                ret=dp[fm][i]+dis[i][nb+1];
            }
        }
        return ret;
    }
};