struct node {
    long long v00, v01, v11, v10;
    void set(long long x) { v00 = v01 = v10 = 0, v11 = max(0ll, x); }
};
struct sgt {
    int n;
    long long query() { return nd[1].v11; }
    void init(const vector<int>& v) {
        n = v.size();
        nd.resize(4 * n + 10);
        iinit(v, 1, n, 1);
    }
    void ud(int pos, int x) { uud(pos, x, 1, n, 1); }
    void uud(int pos, int x, int l, int r, int p) {
        if (l > pos || r < pos)
            return;
        if (l == r) {
            nd[p].set(x);
            return;
        }
        int mid = (l + r) / 2;
        uud(pos, x, l, mid, p * 2);
        uud(pos, x, mid + 1, r, p * 2 + 1);
        pushup(p);
    }
    void iinit(const vector<int>& v, int l, int r, int p) {
        if (l == r) {
            nd[p].set(v[l - 1]);
            return;
        }
        int mid = (l + r) / 2;
        iinit(v, l, mid, 2 * p);
        iinit(v, mid + 1, r, 2 * p + 1);
        pushup(p);
    }
    void pushup(int p) {
        int l = 2 * p, r = 2 * p + 1;
        nd[p].v00 = max(nd[l].v01 + nd[r].v00, nd[l].v00 + nd[r].v10);
        nd[p].v01 = max(nd[l].v01 + nd[r].v01, nd[l].v00 + nd[r].v11);
        nd[p].v10 = max(nd[l].v10 + nd[r].v10, nd[l].v11 + nd[r].v00);
        nd[p].v11 = max(nd[l].v10 + nd[r].v11, nd[l].v11 + nd[r].v01);
    }
    vector<node> nd;
};
class Solution {
   public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        sgt s;
        s.init(nums);
        int l = queries.size(), ans = 0;
        for (int i = 0; i < l; i++) {
            s.ud(queries[i][0] + 1, queries[i][1]);
            ans = (ans + s.query()) % mod;
        }
        return ans;
    }

   private:
    static constexpr int mod = 1000000007;
};
