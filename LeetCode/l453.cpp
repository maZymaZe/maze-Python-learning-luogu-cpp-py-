class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long ans=0, mi=99999999999;
        for(auto i:nums){
            ans+=i;
            if(i<mi)mi=i;
        }
        return ans-nums.size()*mi;
    }
};