struct edge{
    int u,v,nx;
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> h(numCourses+2),d(numCourses+2);
        int l=prerequisites.size();
        if(l==0)return true;
        vector<edge> e;
        e.push_back({0,0,0});
        for(int i=0;i<l;i++){
            e.push_back({prerequisites[i][0],prerequisites[i][1],h[prerequisites[i][0]]});
            h[e[i+1].u]=i+1;
            d[e[i+1].v]++;
        }
        queue<int> q;
        int cnt=0;
        for(int i=0;i<numCourses;i++){
            if(d[i]==0){
                q.push(i),cnt++;
            }
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            for(int i=h[t];i;i=e[i].nx){
                d[e[i].v]--;
                if(d[e[i].v]==0){
                    q.push(e[i].v);cnt++;
                }
            }
        }
        return cnt==numCourses;
    }
};