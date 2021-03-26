class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<int> vis(n);
        vector<vector<int>> t(n, vector<int>());
        int gl=graph.size();
        for(int i=0;i<gl;i++){
            t[graph[i][0]].push_back(graph[i][1]);
        }
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            vis[x]=1;
            for(int i:t[x]){
                if(!vis[i]){
                    q.push(i);
                    if(i==target)return true;
                }
            }
        }
        return false;
    }
};