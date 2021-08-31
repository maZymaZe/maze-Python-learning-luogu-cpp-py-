class Solution {
   public:
    vector<int> ta;
    int nmax;
    void add(int p, int v) {
        while (p < nmax) {
            ta[p] += v;
            p += ((-p) & p);
        }
    }
    int query(int p) {
        int r = 0;
        while (p) {
            r += ta[p];
            p -= ((-p) & p);
        }
        return r;
    }
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        nmax = n * 2 + 10;
        ta.resize(nmax);
        for (auto x : bookings) {
            add(x[0], x[2]);
            add(x[1] + 1, -x[2]);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = query(i + 1);
        return ans;
    }
};