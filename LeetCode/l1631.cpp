struct EDGE{
    int u,v,w;
};
bool cmp(const EDGE&a,const EDGE&b){
    return a.w< b.w;
}
class Solution {
public:
    int n,m;
    int hash(int x, int y){return x*m+y;}
    vector<int> f;
    int ff(int x) { return f[x] == x ? x : f[x] = ff(f[x]); }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size(),m=heights[0].size();
        if(n==1&&m==1)return 0;
        f.resize(n*m);
        int t=n*m-1;
        for(int i=0;i<=t;i++)f[i] =i;
        vector<EDGE> e;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0)e.push_back({hash(i,j),hash(i-1,j),abs(heights[i][j]-heights[i-1][j])});
                if(j>0)e.push_back({hash(i,j),hash(i,j-1),abs(heights[i][j]-heights[i][j-1])});
            }
        }
        sort(e.begin(), e.end(),cmp);
        int l=e.size();
        for(int i=0; i<l;i++){
            f[ff(e[i].u)]= ff(e[i].v);
            if(ff(0)==ff(t))return e[i].w;
        }
        return -1;
    }
};