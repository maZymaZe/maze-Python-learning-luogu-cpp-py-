class Solution {
   public:
    unordered_set<long long> ps;
    void upd(long long x) {
        if (ps.count(x))
            ps.erase(x);
        else
            ps.insert(x);
    }

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long bs = 1e9;
        long long area = 0;
        int edges[4] = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
        for (auto& x : rectangles) {
            for (int i = 0; i < 2; i++)
                edges[i] = min(edges[i], x[i]);
            for (int i = 2; i < 4; i++)
                edges[i] = max(edges[i], x[i]);
            area += 1ll * (x[2] - x[0]) * (x[3] - x[1]);
            upd(bs * x[0] + x[1]);
            upd(bs * x[0] + x[3]);
            upd(bs * x[2] + x[1]);
            upd(bs * x[2] + x[3]);
        }
        if (ps.size() != 4)
            return false;
        upd(bs * edges[0] + edges[1]);
        upd(bs * edges[0] + edges[3]);
        upd(bs * edges[2] + edges[1]);
        upd(bs * edges[2] + edges[3]);
        if (ps.size() != 0)
            return false;
        return area == 1ll * (edges[2] - edges[0]) * (edges[3] - edges[1]);
    }
};