class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=prices.size();
        if(l==0)return 0;
        vector<int> bought(l+1),sold(l+1),freezed(l+1);
        sold[0]=0;bought[0]=-99999999;freezed[0]=-99999999;
        bought[1]=-99999999;freezed[1]=-99999999;
        for(int i=1;i<=l;i++){
            if(i>=1)bought[i]=max(bought[i-1],sold[i-1]-prices[i-1]);
            sold[i]=max(sold[i-1],freezed[i-1]);
            if(i>=2)freezed[i]=bought[i-1]+prices[i-1];
        }
        return max(max(sold[l],freezed[l]),bought[l]+prices[l-1]);
    }
};