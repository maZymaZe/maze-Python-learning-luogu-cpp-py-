class Solution {
   public:
    vector<int> f, x, y;
    int n;
    int ff(int i) {
        if (f[i] == i)
            return i;
        return f[i] = ff(f[i]);
    }
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        n = graph.size();
        f.resize(n);
        x.resize(n);
        for (int i : initial)
            x[i] = 1;
        y = vector<int>(n, 1);
        for (int i = 0; i < n; i++)
            f[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int fi = ff(i), fj = ff(j);
                if (graph[i][j] == 1 && fi != fj) {
                    f[fj] = fi;
                    x[fi] += x[fj];
                    y[fi] += y[fj];
                }
            }
        }
        sort(initial.begin(), initial.end());
        int ans = initial[0], val = -1;
        for (int i : initial) {
            if (x[ff(i)] == 1 && y[ff(i)] > val) {
                ans = i;
                val = y[ff(i)];
            }
        }
        return ans;
    }
};