class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        if(prices.empty())return {};
        stack<int> s;
        int l=prices.size();
        vector<int> ans(l);
        s.push(0);
        for(int i=1;i<l;i++){
            while(!s.empty()&&prices[i]<=prices[s.top()]){
                ans[s.top()]=prices[s.top()]-prices[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            ans[s.top()]=prices[s.top()];
            s.pop();
        }
        return ans;

    }
};