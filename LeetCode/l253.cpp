bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}
class Solution {
   public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0, l = intervals.size();
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < l; i++) {
            if (q.empty()) {
                q.push(intervals[i][1]);
            } else {
                if (q.top() <= intervals[i][0]) {
                    q.pop();
                    q.push(intervals[i][1]);
                } else {
                    q.push(intervals[i][1]);
                }
            }
        }
        return q.size();
    }
};