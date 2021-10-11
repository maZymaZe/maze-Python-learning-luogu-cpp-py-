class Solution {
   public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        priority_queue<int> q;
        int tm = 0;
        for (auto& x : courses) {
            if (tm <= x[1] - x[0]) {
                q.push(x[0]);
                tm += x[0];
            } else {
                if (!q.empty() && q.top() > x[0]) {
                    tm += x[0] - q.top();
                    q.pop();
                    q.push(x[0]);
                }
            }
        }
        return q.size();
    }
};