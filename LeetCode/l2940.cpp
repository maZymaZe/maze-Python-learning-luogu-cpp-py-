struct QR {
    int a, b, id;
    bool operator<(const QR& other) const { return b > other.b; }
};
class Solution {
   public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        int ql = queries.size(), hl = heights.size();
        vector<QR> vq;
        for (int i = 0; i < ql; i++) {
            if (queries[i][0] > queries[i][1]) {
                swap(queries[i][0], queries[i][1]);
            }
            vq.push_back({queries[i][0], queries[i][1], i});
        }
        vector<int> ans(ql);
        deque<int> hi, pos;
        sort(vq.begin(), vq.end());
        int hp = hl - 1;
        for (int i = 0; i < ql; i++) {
            QR q = vq[i];
            if (q.a == q.b) {
                ans[q.id] = q.a;
                continue;
            }
            if (heights[q.a] < heights[q.b]) {
                ans[q.id] = q.b;
                continue;
            }

            while (hp > q.b) {
                while (!hi.empty() && heights[hp] >= hi.front()) {
                    hi.pop_front();
                    pos.pop_front();
                }
                hi.push_front(heights[hp]);
                pos.push_front(hp);
                hp--;
            }
            int ma = max(heights[q.a], heights[q.b]);
            if (hi.empty() || ma >= hi.back()) {
                ans[q.id] = -1;
            } else {
                int idx = upper_bound(hi.begin(), hi.end(), ma) - hi.begin();
                ans[q.id] = pos[idx];
            }
        }
        return ans;
    }
};