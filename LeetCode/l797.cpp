class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> road;
    void dfs(int root, int fa, vector<vector<int>>& graph) {
        if (root == graph.size() - 1) {
            ans.push_back(road);
            return;
        }
        for (auto i : graph[root]) {
            if (i != fa) {
                road.push_back(i);
                dfs(i, root, graph);
                road.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        road.push_back(0);
        dfs(0, -1, graph);
        return ans;
    }
};