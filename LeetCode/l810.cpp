class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int t=0;
        for(int i:nums)t^=i;
        return t==0||(!(nums.size()%2));
    }
};