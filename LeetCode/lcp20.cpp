class Solution {
   public:
    const long long MOD = 1e9 + 7;
    using ll = long long;
    using PLL = pair<ll, ll>;
    int busRapidTransit(int target,
                        int inc,
                        int dec,
                        vector<int>& jump,
                        vector<int>& cost) {
        int n = jump.size();
        priority_queue<PLL, vector<PLL>, greater<PLL> > q;
        q.push({0, (ll)target});
        ll ans = (ll)inc * target;
        while (!q.empty()) {
            auto [t, p] = q.top();
            q.pop();
            if (t >= ans)
                continue;
            ans = min(ans, t + (ll)p * inc);
            for (int i = 0; i < n; i++) {
                ll feed = p % jump[i], nx = p / jump[i];
                if (feed == 0) {
                    q.push({t + cost[i], nx});
                } else {
                    q.push({t + cost[i] + feed * inc, nx});
                    q.push({t + cost[i] + (ll)(jump[i] - feed) * dec, nx + 1});
                }
            }
        }
        return ans % MOD;
    }
};