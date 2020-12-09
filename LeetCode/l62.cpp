class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> ans(n);
        for(int i=0;i<n;i++)
            ans[i]=1;
        for(int i=2;i<=m;i++){
            for(int j=1;j<n;j++){
                ans[j]+=ans[j-1];
            }
        }
        return ans[n-1];
    }
};