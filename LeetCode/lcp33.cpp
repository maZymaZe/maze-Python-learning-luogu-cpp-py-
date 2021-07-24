struct pr {
    int a, b;
    bool operator<(const pr& x) const {
        return (b + a - 1) / a < (x.b + x.a - 1) / x.a;
    }
    int cal() const { return (b + a - 1) / a; }
};
class Solution {
   public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int bs = 0, l = bucket.size(), aop = 0;
        priority_queue<pr> pq;
        for (int i = 0; i < l; i++) {
            if (bucket[i] == 0 && vat[i] != 0) {
                bs++, bucket[i]++;
            }
            if (vat[i] != 0)
                pq.push({bucket[i], vat[i]});
        }
        int ans = 0x3f3f3f3f;
        if (pq.empty())
            return 0;
        ans = min(ans, pq.top().cal());
        while (1) {
            pr x = pq.top();
            pq.pop();
            aop++;
            x.a++;
            pq.push(x);
            int nx = pq.top().cal() + aop;
            if (nx > ans + 100)
                break;
            else
                ans = min(nx, ans);
        }
        return bs + ans;
    }
};