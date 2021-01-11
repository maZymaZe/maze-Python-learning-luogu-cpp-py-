class Solution {
public:
    int n,m;
    vector<int> f,vis;
    vector<vector<int>> w;
    vector<vector<char>> cc;
    int ff(int x){ return f[x]==x ? x: f[x]=ff(f[x]); }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        n=s.size(),m=pairs.size();
        f.resize(n),w.resize(n),vis.resize(n),cc.resize(n);
        for(int i=0;i<n;i++)f[i]=i;
        for(int i=0;i<m;i++){
            f[ff(pairs[i][0])]=ff(pairs[i][1]);
        }
        for(int i=0;i<n;i++){
            w[ff(i)].push_back(i);
            cc[ff(i)].push_back(s[i]);
        }
        for(int i=0;i<n;i++){
            sort(cc[i].begin(),cc[i].end());
            for(int j=0;j<w[i].size();j++){
                s[w[i][j]]=cc[i][j];
            }
        }
        return s;
    }
};