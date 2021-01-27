class Solution {
public:
    int ff(int x,vector<int>&v){
        if(v[x]==x)return x;
        return v[x]=ff(v[x],v);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> e1,e2,e3;
        int l=edges.size();
        for(int i=0; i<l; i++){
            if(edges[i][0]==1)e1.push_back(edges[i]);
            if(edges[i][0]==2)e2.push_back(edges[i]);
            if(edges[i][0]==3)e3.push_back(edges[i]);
        }
        vector<int> f0(n+1);
        for(int i=0;i<=n;i++)f0[i]=i;
        int l1=e1.size(),l2=e2.size(),l3=e3.size();
        int c0=0,c1=0,c2=0;
        for(int i=0;i<l3;i++){
            int fx=ff(e3[i][1],f0),fy=ff(e3[i][2],f0);
            if(fx!= fy){
                f0[fx]=fy;
                c0++;
            }
        }
        if(c0==n-1)return l-c0;
        vector<int> f1=f0,f2=f0;
        for(int i=0;i<l1;i++){
            int fx=ff(e1[i][1],f1),fy=ff(e1[i][2],f1);
            if(fx!= fy){
                f1[fx]=fy;
                c1++;
            }
        }
        for(int i=0;i<l2;i++){
            int fx=ff(e2[i][1],f2),fy=ff(e2[i][2],f2);
            if(fx!= fy){
                f2[fx]=fy;
                c2++;
            }
        }
        if(c0+c1!=n-1||c0+c2!=n-1)return -1;
        return l-c0-c1-c2;
    }
};