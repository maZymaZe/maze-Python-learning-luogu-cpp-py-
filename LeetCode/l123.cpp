class Solution {
public:
    int maxProfit(vector<int>& prices) {       
        int a,b,c,d,e,l=prices.size();;
        e=0;a=b=c=d=-0x3f3f3f3f;
        for(int i=1;i<=l;i++){
            a=max(b+prices[i-1],a);
            b=max(b,c-prices[i-1]);
            c=max(d+prices[i-1],c);
            d=max(d,e-prices[i-1]);
           
        }
        return max(max(e,a),c);
    }
};