class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        if(prices.empty())return {};
        stack<int> s;
        int l=prices.size();
        vector<int> ans(l);
        s.push(0);
        for(int i=l-1;i>=0;i--){
            while(prices[i]<s.top()){
                s.pop();
            }
            ans[i]=prices[i]-s.top();
            s.push(prices[i]);
        }
        return ans;

    }
};