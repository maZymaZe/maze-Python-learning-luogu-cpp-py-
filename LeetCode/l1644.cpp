typedef pair<int, int> pii;

class UnionFind {
    int m, n;
    vector<vector<pii>> root;
    vector<vector<int>> size;

   public:
    UnionFind(int m, int n) {
        this->m = m;
        this->n = n;
        this->root = vector<vector<pii>>(m, vector<pii>(n));
        this->size = vector<vector<int>>(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                root[i][j] = make_pair(i, j);
                size[i][j] = 1;
            }
        }
    }

    pii find(int i, int j) {
        pii rootArr = root[i][j];
        int ri = rootArr.first, rj = rootArr.second;
        if (ri == i && rj == j) {
            return rootArr;
        }
        return find(ri, rj);
    }

    void Uni(int i1, int j1, int i2, int j2) {
        auto [ri1, rj1] = find(i1, j1);
        auto [ri2, rj2] = find(i2, j2);
        if (ri1 != ri2 || rj1 != rj2) {
            if (size[ri1][rj1] >= size[ri2][rj2]) {
                root[ri2][rj2] = make_pair(ri1, rj1);
                size[ri1][rj1] += size[ri2][rj2];
            } else {
                root[ri1][rj1] = make_pair(ri2, rj2);
                size[ri2][rj2] += size[ri1][rj1];
            }
        }
    }
};

class Solution {
   public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        UnionFind uf(m, n);
        for (int i = 0; i < m; i++) {
            unordered_map<int, vector<pii>> num2indexList;
            for (int j = 0; j < n; j++) {
                num2indexList[matrix[i][j]].emplace_back(i, j);
            }
            for (auto [_, indexList] : num2indexList) {
                auto [i1, j1] = indexList[0];
                for (int k = 1; k < indexList.size(); k++) {
                    auto [i2, j2] = indexList[k];
                    uf.Uni(i1, j1, i2, j2);
                }
            }
        }
        for (int j = 0; j < n; j++) {
            unordered_map<int, vector<pii>> num2indexList;
            for (int i = 0; i < m; i++) {
                num2indexList[matrix[i][j]].emplace_back(i, j);
            }
            for (auto [_, indexList] : num2indexList) {
                auto [i1, j1] = indexList[0];
                for (int k = 1; k < indexList.size(); k++) {
                    auto [i2, j2] = indexList[k];
                    uf.Uni(i1, j1, i2, j2);
                }
            }
        }

        vector<vector<int>> degree(m, vector<int>(n));
        unordered_map<int, vector<pii>> adj;
        for (int i = 0; i < m; i++) {
            unordered_map<int, pii> num2index;
            for (int j = 0; j < n; j++) {
                num2index[matrix[i][j]] = make_pair(i, j);
            }
            vector<int> sortedArray;
            for (auto [key, _] : num2index) {
                sortedArray.emplace_back(key);
            }
            sort(sortedArray.begin(), sortedArray.end());
            for (int k = 1; k < sortedArray.size(); k++) {
                auto [i1, j1] = num2index[sortedArray[k - 1]];
                auto [i2, j2] = num2index[sortedArray[k]];
                auto [ri1, rj1] = uf.find(i1, j1);
                auto [ri2, rj2] = uf.find(i2, j2);
                degree[ri2][rj2]++;
                adj[ri1 * n + rj1].emplace_back(ri2, rj2);
            }
        }
        for (int j = 0; j < n; j++) {
            unordered_map<int, pii> num2index;
            for (int i = 0; i < m; i++) {
                num2index[matrix[i][j]] = make_pair(i, j);
            }
            vector<int> sortedArray;
            for (auto [key, _] : num2index) {
                sortedArray.emplace_back(key);
            }
            sort(sortedArray.begin(), sortedArray.end());
            for (int k = 1; k < sortedArray.size(); k++) {
                auto [i1, j1] = num2index[sortedArray[k - 1]];
                auto [i2, j2] = num2index[sortedArray[k]];
                auto [ri1, rj1] = uf.find(i1, j1);
                auto [ri2, rj2] = uf.find(i2, j2);
                degree[ri2][rj2]++;
                adj[ri1 * n + rj1].emplace_back(ri2, rj2);
            }
        }

        unordered_set<int> rootSet;
        vector<vector<int>> ranks(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                auto [ri, rj] = uf.find(i, j);
                rootSet.emplace(ri * n + rj);
                ranks[ri][rj] = 1;
            }
        }
        queue<pii> q;
        for (int val : rootSet) {
            if (degree[val / n][val % n] == 0) {
                q.emplace(val / n, val % n);
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto [ui, uj] : adj[i * n + j]) {
                degree[ui][uj]--;
                if (degree[ui][uj] == 0) {
                    q.emplace(ui, uj);
                }
                ranks[ui][uj] = max(ranks[ui][uj], ranks[i][j] + 1);
            }
        }
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                auto [ri, rj] = uf.find(i, j);
                res[i][j] = ranks[ri][rj];
            }
        }
        return res;
    }
};
