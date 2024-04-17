class Solution {
   public:
    vector<int> f, isin, y;
    int n;
    int ff(int x) {
        if (f[x] == x)
            return x;
        return f[x] = ff(f[x]);
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        n = graph.size();
        f.resize(n);
        isin.resize(n);
        y.resize(n);
        sort(initial.begin(), initial.end());
        for (int i : initial)
            isin[i] = 1;
        for (int i = 0; i < n; i++) {
            f[i] = i;
            y[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!(graph[i][j]) || isin[i] || isin[j])
                    continue;
                int fi = ff(i), fj = ff(j);
                if (fi != fj) {
                    f[fj] = fi;
                    y[fi] += y[fj];
                }
            }
        }
        vector<vector<int>> vis(n, vector<int>(n));
        vector<int> cnt(n, -1);
        for (int i : initial) {
            for (int j = 0; j < n; j++) {
                int fj = ff(j);
                if (graph[i][j]) {
                    if (cnt[fj] == -1) {
                        cnt[fj] = i;
                    } else if (cnt[fj] != i)
                        cnt[fj] = n;
                }
            }
        }
        vector<int> ta(n);
        for (int i = 0; i < n; i++) {
            if (ff(i) == i && !isin[i] && cnt[i] >= 0 && cnt[i] < n) {
                ta[cnt[i]] += y[i];
            }
        }
        int ans = initial[0], val = 0;
        for (int i : initial) {
            if (ta[i] > val) {
                ans = i, val = ta[i];
            }
        }

        return ans;
    }
};