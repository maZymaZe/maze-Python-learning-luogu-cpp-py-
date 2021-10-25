class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int le = heights.size();
        vector<int> rr(le);
        stack<int> r;
        for (int i = le - 1; i >= 0; i--) {
            while ((!r.empty()) && (heights[i] <= heights[r.top()])) {
                r.pop();
            }
            if (r.empty()) {
                r.push(i);
                rr[i] = le;
            } else {
                rr[i] = r.top();
                r.push(i);
            }
        }
        vector<int> ll(le);
        stack<int> l;
        for (int i = 0; i < le; i++) {
            while ((!l.empty()) && (heights[i] <= heights[l.top()])) {
                l.pop();
            }
            if (l.empty()) {
                l.push(i);
                ll[i] = -1;
            } else {
                ll[i] = l.top();
                l.push(i);
            }
        }
        int ans = 0;
        for (int i = le - 1; i >= 0; i--) {
            ans = max(ans, (rr[i] - 1 - ll[i]) * heights[i]);
        }
        return ans;
    }
};