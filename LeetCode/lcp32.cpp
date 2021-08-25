#define pii pair<int, int>
class Solution {
   public:
    int processTasks(vector<vector<int>>& tasks) {
        priority_queue<pii, vector<pii>, greater<pii>> q;
        sort(tasks.begin(), tasks.end());
        vector<int> nt = {(int)1e9 + 5, (int)1e9 + 5, 1};
        vector<vector<int>> nwt = tasks;
        nwt.push_back(nt);
        int ret = 0;
        for (auto t : nwt) {
            while (!q.empty() && q.top().first + ret < t[0]) {
                if (q.top().first + ret >= q.top().second)
                    q.pop();
                else
                    ret += min(q.top().second, t[0]) - (q.top().first + ret);
            }
            q.push({t[1] - t[2] + 1 - ret, t[1] + 1});
        }
        return ret;
    }
};