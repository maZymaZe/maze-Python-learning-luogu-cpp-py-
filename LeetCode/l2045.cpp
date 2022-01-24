class Solution {
   public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> nx(n + 1);
        for (const auto& edge : edges) {
            nx[edge[0]].push_back(edge[1]);
            nx[edge[1]].push_back(edge[0]);
        }
        queue<int> q, t;
        vector<int> oc(n + 1), tw(n + 1);
        q.push(1), t.push(0);
        while (!q.empty()) {
            int h = q.front(), ht = t.front();
            q.pop(), t.pop();
            for (auto& i : nx[h]) {
                int nt = -1;
                if (ht % (change * 2) < change) {
                    nt = ht + time;
                } else {
                    nt = ht - ht % (2 * change) + 2 * change + time;
                }
                if (i == 1) {
                    if (tw[i] == 0) {
                        tw[i] = nt;
                        q.push(i), t.push(nt);
                    }
                } else {
                    if (oc[i] == 0) {
                        oc[i] = nt;
                        q.push(i), t.push(nt);
                    } else if (tw[i] == 0 && nt != oc[i]) {
                        tw[i] = nt;
                        q.push(i), t.push(nt);
                    }
                }
            }
        }
        return tw[n];
    }
};