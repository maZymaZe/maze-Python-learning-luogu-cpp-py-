class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int s[1002]={0};
        s[1]=cost[1];s[0]=cost[0];
        for(int i=2;i<cost.size();i++){
            s[i]=min(s[i-1],s[i-2])+cost[i];
        }
        return s[cost.size()-1];
    }
};