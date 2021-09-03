class Solution {
   public:
    vector<vector<int>> pre;
    vector<int> degree;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        pre.resize(numCourses);
        degree.resize(numCourses);
        for (auto x : prerequisites) {
            pre[x[1]].push_back(x[0]);
            degree[x[0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for (auto i : pre[x]) {
                degree[i]--;
                if (!degree[i])
                    q.push(i);
            }
        }
        if (ans.size() == numCourses)
            return ans;
        return {};
    }
};