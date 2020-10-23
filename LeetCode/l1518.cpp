class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int e=0,ans=0;
        while(numBottles){
            e+=numBottles;
            ans+=numBottles;
            numBottles=e/numExchange;
            e%=numExchange;
        }
        return ans;
    }
};