class Solution {
   public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        int l = matrix.size();
        if(l==0)return{};
        if(l==1){
            if(matrix[0][0])return{};
            return {0,0,1};
        }
        vector<vector<vector<int>>> dp(l, vector<vector<int>>(l, vector<int>(2)));
        int mxs = -1, ax = 0, ay = 0;
        for(int i=l-1; i>=0; i--){
            for(int j=l-1;j>=0;j--){
                if(matrix[i][j])dp[i][j][1] =dp[i][j][0]=0;
                else{
                    if(i<l-1)dp[i][j][1]=dp[i+1][j][1]+1;
                    else dp[i][j][1]=1;

                    if(j<l-1)dp[i][j][0]=dp[i][j+1][0]+1;
                    else dp[i][j][0]=1;

                    int len=min(dp[i][j][0],dp[i][j][1]);
                    while(len>=mxs){
                        if(dp[i+len-1][j][0]>=len&&dp[i][j+len-1][1]>=len){
                            mxs=len,ax=i,ay=j;
                            break;
                        }
                        len--;
                    }
                }
            }
        }
        vector<int> ans;
        if (mxs <= 0)
            return ans;
        ans.push_back(ax), ans.push_back(ay), ans.push_back(mxs);
        return ans;
    }
};