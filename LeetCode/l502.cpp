struct pr {
    int a, b;
    bool operator<(const pr& x) const { return b < x.b; }
};
bool cmp(const pr& a, const pr& b) {
    return a.a < b.a;
}
class Solution {
   public:
    int findMaximizedCapital(int k,
                             int w,
                             vector<int>& profits,
                             vector<int>& capital) {
        int l = profits.size();
        vector<pr> v(l);
        for (int i = 0; i < l; i++) {
            v[i] = {capital[i], profits[i]};
        }
        sort(v.begin(), v.end(),cmp);
        int p = 0, cnt = 0;
        priority_queue<pr> pq;
        while (p < l && v[p].a <= w)
            pq.push(v[p]), p++;
        while (!pq.empty()) {
            if (cnt >= k)
                break;
            w += pq.top().b;
            pq.pop();
            cnt++;
            while (p < l && v[p].a <= w)
                pq.push(v[p]), p++;
        }
        return w;
    }
};