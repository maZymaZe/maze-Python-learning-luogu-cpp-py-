class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int tot=0,ma,l=nums.size();
        for (int i=0;i<k;i++)tot+=nums[i];
        ma=tot;
        for(int i=k;i<l;i++){
            tot+=nums[i];
            tot-=nums[i-k];
            if(tot>ma)ma=tot;
        }
        return 1.0*ma/k;
    }
};