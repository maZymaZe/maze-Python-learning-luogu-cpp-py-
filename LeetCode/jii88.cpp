class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int l = cost.size();
        for (int i = 2; i < l; i++) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return cost[l - 1];
    }
};