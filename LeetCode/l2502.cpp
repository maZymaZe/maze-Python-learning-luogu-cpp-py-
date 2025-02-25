class Allocator {
   public:
    vector<int> nx, pr, us;
    map<int, vector<int>> st;
    int N;
    Allocator(int n) {
        nx.resize(n);
        pr.resize(n);
        us.resize(n);
        us[0] = 0;
        nx[0] = n - 1;
        pr[n - 1] = 0;
        N = n;
    }

    int allocate(int size, int mID) {
        int p = 0;
        while (p < N) {
            if (us[p] == 0 && (nx[p] - p + 1 >= size)) {
                if (nx[p] - p + 1 > size) {
                    int np = p + size;
                    nx[np] = nx[p];
                    pr[nx[p]] = np;
                    nx[p] = np - 1;
                    pr[nx[p]] = p;
                }
                us[p] = 1;
                st[mID].push_back(p);
                return p;
            }
            p = nx[p] + 1;
        }
        return -1;
    }

    int freeMemory(int mID) {
        int tot = 0;
        for (int x : st[mID]) {
            tot += (nx[x] - x + 1);
            int y = nx[x] + 1;
            us[x] = 0;
            if (y < N && us[y] == 0) {
                pr[nx[x]] = 0;
                nx[x] = nx[y];
                nx[y] = 0;
                pr[nx[x]] = x;
            }
            int z = x - 1;
            if (z >= 0) {
                int zz = pr[z];
                if (us[zz] == 0) {
                    pr[z] = 0;
                    nx[zz] = nx[x];
                    pr[nx[x]] = zz;
                    nx[x] = 0;
                }
            }
        }
        st[mID].clear();
        return tot;
    }
};