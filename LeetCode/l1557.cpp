class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> v(n),ans;
        for (auto it:edges)v[it[1]]++;
        for(int i=0;i<n;i++)if(!v[i])ans.push_back(i);
        return ans;
    }
};