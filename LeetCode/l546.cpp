class Solution {
public:
    int dp[102][102][102];
    int removeBoxes(vector<int>& boxes) {
        memset(dp,0,sizeof(dp));
        return cal(boxes,0,boxes.size()-1,0);
    }
    int cal(vector<int>& boxes,int l,int r,int k){
        if(l>r)return 0;
        if(dp[l][r][k])return dp[l][r][k];
        
        while(r>l&&boxes[r]==boxes[r-1])r--,k++;
        dp[l][r][k]=cal(boxes,l,r-1,0)+(k+1)*(k+1);
        for(int i=l;i<r;i++){
            if(boxes[i]==boxes[r])
                dp[l][r][k]=max(dp[l][r][k],cal(boxes,l,i,k+1)+cal(boxes,i+1,r-1,0));
        }
        return dp[l][r][k];
    }
};