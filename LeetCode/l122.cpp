class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tot=0,l=prices.size();
        for(int i=1;i<l;i++)tot+=max(0,prices[i]-prices[i-1]);
        return tot;
    }
};