class Solution {
   public:
    int ans;
    int nn;
    vector<int> c;
    int dfs(int t) {
        if (t >= nn)
            return 0;
        int t1 = dfs(2 * t + 1), t2 = dfs(2 * t + 2);
        ans += abs(t1 - t2);
        return c[t] + max(t1, t2);
    }
    int minIncrements(int n, vector<int>& cost) {
        nn = n, ans = 0, c = cost;
        dfs(0);
        return ans;
    }
};