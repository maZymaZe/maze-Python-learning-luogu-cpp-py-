class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        int l=rooms.size();
        vector<int> vis(l);
        q.push(0);
        while(!q.empty()){
            int k=q.front();
            q.pop();
            if(vis[k])continue;
            vis[k]=1;
            for(int i=room[k].size()-1;i>=0;i--)q.push(room[k][i]);
        }
        for(int i=0;i<l;i++)if(!vis[i])return false;
        return true;
    }
};