class Solution {
public:
    vector<int> f,u;
    int ff(int x) {
        if (f[x] == x)return x;
        return f[x]=ff(f[x]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int l=connections.size(),ans=0;
        if(l<n-1)return -1;
        u.resize(n+1);
        f.resize(n+1);
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=0;i<l;i++){
            f[ff(connections[i][0]+1)]=ff(connections[i][1]+1);
        }
        for(int i=1;i<=n;i++){
            if(!u[ff(i)])ans++,u[ff(i)]=1;
        }
        return ans-1;
    }
};