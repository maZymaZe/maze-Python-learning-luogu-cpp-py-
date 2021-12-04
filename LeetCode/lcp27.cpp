class BlackBox {
   public:
    vector<pair<int, int>> gp, gn;
    vector<map<int, int>> gs;

    BlackBox(int n, int m) {
        int ptc = (n + m) * 2;
        gp.assign(ptc, {-1, -1});
        gn.assign(ptc, {-1, -1});
        for (int i = 0; i < ptc; i++) {
            if (i && i != m + n && gp[i].first == -1) {
                cg(n, m, i, 1);
            }
            if (i != m && i != m * 2 + n && gn[i].first == -1) {
                cg(n, m, i, -1);
            }
        }
    }
    void cg(int n, int m, int idx, int d) {
        int gid = gs.size();
        int gl = 0;
        gs.emplace_back();
        while (!(d == 1 && gp[idx].first != -1) &&
               !(d == -1 && gn[idx].first != -1)) {
            if (d == 1) {
                gp[idx] = {gid, gl++};
                idx = (n + m) * 2 - idx;
            } else {
                gn[idx] = {gid, gl++};
                if (idx <= m * 2) {
                    idx = m * 2 - idx;
                } else {
                    idx = (m * 2 + n) * 2 - idx;
                }
            }
            if (idx != 0 && idx != m && idx != n + m && idx != m * 2 + n)
                d = -d;
        }
    }
    int open(int index, int direction) {
        if (auto [gid, gl] = gp[index]; gid != -1) {
            gs[gid].emplace(gl, index);
        }
        if (auto [gid, gl] = gn[index]; gid != -1) {
            gs[gid].emplace(gl, index);
        }
        auto [gid, gl] = (direction == 1 ? gp[index] : gn[index]);
        auto& st = gs[gid];
        if (auto iter = st.upper_bound(gl); iter != st.end()) {
            return iter->second;
        }
        return st.begin()->second;
    }

    void close(int index) {
        if (auto [gid, gl] = gp[index]; gid != -1) {
            gs[gid].erase(gl);
        }
        if (auto [gid, gl] = gn[index]; gid != -1) {
            gs[gid].erase(gl);
        }
    }
};

/**
 * Your BlackBox object will be instantiated and called as such:
 * BlackBox* obj = new BlackBox(n, m);
 * int param_1 = obj->open(index,direction);
 * obj->close(index);
 */