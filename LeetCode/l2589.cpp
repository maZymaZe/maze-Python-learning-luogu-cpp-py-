struct NODE {
    int pre;
    int nx;
};
class Solution {
   public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int u[2003] = {0}, l = tasks.size(), ans = 0;
        NODE nd[2003];
        for (int i = 0; i < 2003; i++) {
            nd[i].nx = i + 1;
            nd[i].pre = i - 1;
        }
        for (int i = 0; i < l; i++) {
            int t = nd[nd[tasks[i][1]].nx].pre;
            while (tasks[i][2] > 0) {
                if (!u[t]) {
                    u[t] = 1;
                    ans++;
                    for (int j = i; j < l; j++) {
                        if (t >= tasks[j][0] && t <= tasks[j][1]) {
                            tasks[j][2]--;
                        }
                    }
                    nd[nd[t].pre].nx = nd[t].nx;
                    nd[nd[t].nx].pre = nd[t].pre;
                }
                t = nd[t].pre;
            }
        }
        return ans;
    }
};