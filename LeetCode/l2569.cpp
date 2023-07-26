struct node {
    int l, r, sum;
    bool lazy;
    node() { l = r = sum = lazy = 0; }
};
class tree {
   public:
    vector<node> a;
    tree(vector<int>& v) {
        int n = v.size();
        a.resize(n * 4 + 10);
        build(1, 0, n - 1, v);
    }
    int qlr(int l, int r) { return q(1, l, r); }
    void op1(int l, int r) { modify(1, l, r); }
    void build(int x, int l, int r, const vector<int>& v) {
        a[x].l = l, a[x].r = r;
        a[x].lazy = 0;
        if (l == r) {
            a[x].sum = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * x, l, mid, v);
        build(2 * x + 1, mid + 1, r, v);
        a[x].sum = a[2 * x].sum + a[2 * x + 1].sum;
    }
    void pd(int x) {
        if (a[x].lazy) {
            a[2 * x].lazy ^= 1;
            a[2 * x].sum = a[2 * x].r - a[2 * x].l + 1 - a[2 * x].sum;
            a[2 * x + 1].lazy ^= 1;
            a[2 * x + 1].sum =
                a[2 * x + 1].r - a[2 * x + 1].l + 1 - a[2 * x + 1].sum;
            a[x].lazy = 0;
        }
    }
    void modify(int x, int l, int r) {
        if (l <= a[x].l && r >= a[x].r) {
            a[x].sum = a[x].r - a[x].l + 1 - a[x].sum;
            a[x].lazy ^= 1;
            return;
        }
        pd(x);
        if (a[2 * x].r >= l) {
            modify(2 * x, l, r);
        }
        if (a[2 * x + 1].l <= r) {
            modify(2 * x + 1, l, r);
        }
        a[x].sum = a[x * 2].sum + a[x * 2 + 1].sum;
    }
    int q(int x, int l, int r) {
        if (l <= a[x].l && r >= a[x].r) {
            return a[x].sum;
        }
        if (a[x].r < l || a[x].l > r)
            return 0;
        int ret = 0;
        if (a[2 * x].r >= l)
            ret += q(2 * x, l, r);
        if (a[2 * x + 1].l <= r) {
            ret += q(2 * x + 1, l, r);
        }
        return ret;
    }
};
class Solution {
   public:
    vector<long long> handleQuery(vector<int>& nums1,
                                  vector<int>& nums2,
                                  vector<vector<int>>& queries) {
        int n = nums1.size(), m = queries.size();
        long long sum = accumulate(nums2.begin(), nums2.end(), 0LL);
        vector<long long> ans;
        tree t(nums1);
        for (int i = 0; i < m; i++) {
            if (queries[i][0] == 1) {
                t.op1(queries[i][1], queries[i][2]);
            } else if (queries[i][0] == 2) {
                sum += (long long)t.qlr(0, n - 1) * queries[i][1];
            } else {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};