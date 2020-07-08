class Solution {
public:
    int minJumps(vector<int>& arr) {
        int l=arr.size();
        vector<int> vis(l);
        unordered_map<int,vector<int> > mp;
        for(int i=0;i<l;i++){
            if(mp.count(arr[i])){
                mp[arr[i]].push_back(i);
            }
            else{
                vector<int> t;
                t.push_back(i);
                mp.insert({arr[i],t});
            }
        }
        if(l==1)return 0;
        queue<int> q;
        q.push(0);
        while(1){
            int n=q.front();
            if(n+1<l&&vis[n+1]==0){
                q.push(n+1);
                vis[n+1]=vis[n]+1;
                if(n+1==l-1)return vis[n+1];
            }
            if(n-1>0&&vis[n-1]==0){
                q.push(n-1);
                vis[n-1]=vis[n]+1;
            }
            while(!mp[arr[n]].empty()){
                int t=mp[arr[n]].back();
                if(t!=0&&t!=n&&vis[t]==0){
                    q.push(t);
                    vis[t]=vis[n]+1;
                    if(t==l-1)return vis[n]+1;
                }
                mp[arr[n]].pop_back();
            }
            q.pop();
        }
    }
};