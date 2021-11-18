class Solution {
   public:
    unordered_map<string, int> variables;
    vector<int> f;
    vector<double> w;
    int ff(int x) {
        if (f[x] != x) {
            int fa = ff(f[x]);
            w[x] = w[x] * w[f[x]];
            f[x] = fa;
        }
        return f[x];
    }
    void merge(int x, int y, double v) {
        int fx = ff(x), fy = ff(y);
        f[fx] = fy;
        w[fx] = v * w[y] / w[x];
    }
    int n, nv = 0;
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        n = equations.size();
        for (int i = 0; i < n; i++) {
            if (!variables.count(equations[i][0])) {
                variables[equations[i][0]] = nv++;
            }
            if (!variables.count(equations[i][1])) {
                variables[equations[i][1]] = nv++;
            }
        }
        f.resize(nv);
        w.resize(nv);
        for (int i = 0; i < nv; i++) {
            f[i] = i;
            w[i] = 1.0;
        }
        for (int i = 0; i < n; i++) {
            int va = variables[equations[i][0]],
                vb = variables[equations[i][1]];
            merge(va, vb, values[i]);
        }
        vector<double> ans;
        for (auto& i : queries) {
            double res = -1.0;
            if (variables.count(i[0]) && variables.count(i[1])) {
                int ia = variables[i[0]], ib = variables[i[1]];
                int fa = ff(ia), fb = ff(ib);
                if (fa == fb)
                    res = w[ia] / w[ib];
            }
            ans.push_back(res);
        }
        return ans;
    }
};