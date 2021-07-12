class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> ans;
        vector<int> mi(n,0x3f3f3f3f),ma(m,-0x3f3f3f3f);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mi[i]=min(mi[i],matrix[i][j]);
                ma[j]=max(ma[j],matrix[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==ma[j]&&matrix[i][j]==mi[i])ans.push_back(ma[j]);
            }
        }
        return ans;

    }
};