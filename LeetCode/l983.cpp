class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int l=days.size();
        int dp[370];
        dp[0]=0;
        for(int i=1;i<=l;i++){
            dp[i]=dp[i-1]+costs[0];
            int j=i-1;
            while(j>0&&days[i-1]-days[j-1]<7)j--;
            dp[i]=min(dp[j]+costs[1],dp[i]);
            while(j>0&&days[i-1]-days[j-1]<30)j--;
            dp[i]=min(dp[j]+costs[2],dp[i]);
        }
        return dp[l];
    }
};