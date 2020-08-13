class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int c[2]={0};
        for(int i=chips.size()-1;i>=0;i--)c[chips[i]%2]++;
        return min(c[0],c[1]);
    }
};