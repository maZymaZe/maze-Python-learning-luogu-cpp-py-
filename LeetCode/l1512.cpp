class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int c[101]={0},ans=0;
        for(int i:nums)c[i]++;
        for(int i=0;i<=100;i++)ans+=(c[i]-1)*c[i]/2;
        return ans;
    }
};