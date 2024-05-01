struct PR {
    int c, id;
    bool operator<(const PR& other) const {
        if (c == other.c)
            return id > other.id;
        return c > other.c;
    }
};
class Solution {
   public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<PR> lq, rq;
        lq.push({(int)1e7, 0});
        rq.push({(int)1e7, 0});
        int l = costs.size();
        int lp = 0, rp = l - 1;
        for (int i = 0; i < candidates; i++) {
            lq.push({costs[i], i});
            lp++;
        }
        for (int i = l - 1, j = 0; i >= 0 && j < candidates; j++, i--) {
            if (i == lp - 1)
                break;
            rq.push({costs[i], i});
            rp--;
        }
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            PR a = lq.top(), b = rq.top();
            if (a < b) {
                ans += b.c;
                rq.pop();
                if (rp >= lp) {
                    rq.push({costs[rp], rp});
                    rp--;
                }
            } else {
                ans += a.c;
                lq.pop();
                if (lp <= rp) {
                    lq.push({costs[lp], lp});
                    lp++;
                }
            }
        }
        return ans;
    }
};