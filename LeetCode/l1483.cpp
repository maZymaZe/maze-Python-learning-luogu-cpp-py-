class TreeAncestor {
public:
    vector<vector<int>> fa;
    int N;
    TreeAncestor(int n, vector<int>& parent) {
        N=n;
        fa.resize(N+1);
        fa[0].resize(17);
        for(int i=1;i<=n;i++){
            fa[i].resize(17);
            fa[i][0]=i;
            fa[i][1]=parent[i-1]+1;
        }
        for(int i=2;i<17;i++){
            for(int j=1;j<=n;j++){
                fa[j][i]=fa[fa[j][i-1]][i-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        node++;
        int p=node;
        for(int i=0;i<=16;i++){
            if(k&(1 << i)){
                k-=(1<<i);
                p=fa[p][i+1];
            }
        }
        if(p==0)return -1;
        return p-1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */