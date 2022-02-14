class Solution {
   public:
    int numOfMinutes(int n,
                     int headID,
                     vector<int>& manager,
                     vector<int>& informTime) {
        vector<vector<int>> ss(n);
        vector<int> t(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (manager[i] != -1)
                ss[manager[i]].push_back(i);
        queue<int> q;
        q.push(headID);
        t[headID] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto i : ss[x]) {
                q.push(i);
                t[i] = t[x] + informTime[x];
                ans = max(ans, t[i]);
            }
        }
        return ans;
    }
};