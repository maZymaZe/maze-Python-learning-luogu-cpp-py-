class Solution {
   public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<int>> nx(numCourses);
        vector<vector<int>> cn(numCourses, vector<int>(numCourses));
        vector<bool> ans;
        for (auto& v : prerequisites) {
            nx[v[1]].push_back(v[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            queue<int> q;
            vector<int> vis(numCourses);
            for (int j : nx[i]) {
                q.push(j);
            }
            while (!q.empty()) {
                int x = q.front();

                q.pop();
                if (vis[x])
                    continue;
                else
                    vis[x] = 1;
                cn[i][x] = 1;
                for (int j : nx[x]) {
                    q.push(j);
                }
            }
        }
        for (auto& v : queries) {
            ans.push_back(cn[v[1]][v[0]]);
        }
        return ans;
    }
};