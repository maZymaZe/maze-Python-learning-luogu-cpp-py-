class Solution {
   public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        int le = events.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0, cur = -1, p = 0;
        while (p != le || !pq.empty()) {
            if (p < le && pq.empty()) {
                cur = events[p][0];
            }
            while (p < le && events[p][0] <= cur) {
                pq.push(events[p][1]);
                p++;
            }
            while (!pq.empty() && pq.top() < cur) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans++;
                pq.pop();
            }
            cur++;
            while (!pq.empty() && pq.top() < cur) {
                pq.pop();
            }
        }
        return ans;
    }
};